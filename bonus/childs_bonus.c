/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:24:27 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/05 03:06:29 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

// Function suggested by samusanc to manage the possible failure of the
// creation of the child in the execution of the initialization of the
// variable that houses the pid.
int	ft_fork_manage(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Infile child pid creation proccess failed");
	return (pid);
}

void	ft_outfile_child_b(char **argv, int cmd, char **envp, int *pipe_fd)
{
	int		outfile_fd;
	pid_t	child_pid;

	child_pid = ft_fork_manage();
	if (child_pid == 0)
	{
		outfile_fd = open(argv[cmd + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (close(pipe_fd[1]) == -1)
			ft_error("Output child failed closing the write fd pipe");
		if (outfile_fd == -1 || dup2(pipe_fd[0], STDIN_FILENO) == -1
			|| dup2(outfile_fd, STDOUT_FILENO) == -1)
			ft_error("Outfile fd creation or dup2 failed");
		if (close(pipe_fd[0]) == -1 || close(outfile_fd) == -1)
			ft_error("Some fd close failed in the output child proccess");
		ft_exec(argv[cmd], envp);
	}
}

void	ft_middle_child(char *cmd_argv, char **envp, int *left, int *right)
{
	pid_t	child_pid;

	child_pid = ft_fork_manage();
	if (child_pid == 0)
	{
		if (close(left[1]) == -1)
			ft_error("A Middle child failed closing unused L1 fd");
		if (close(right[0]) == -1)
			ft_error("A Middle child failed closing unused R0 fd");
		if (dup2(left[0], STDIN_FILENO) == -1)
			ft_error("A Middle child failed in L0 dup2");
		if (dup2(right[1], STDOUT_FILENO) == -1)
			ft_error("A Middle child failed in R1 dup2");
		if (close(left[0]) == -1)
			ft_error("A Middle child failed closing L0 fd post dups2");
		if (close(right[1]) == -1)
			ft_error("A Middle child failed closing R1 fd post dups2");
		ft_exec(cmd_argv, envp);
	}
}

void	ft_infile_child(char **argv, char **envp, int *pipe_fd)
{
	int		infile_fd;
	pid_t	child_pid;

	child_pid = ft_fork_manage();
	if (child_pid == 0)
	{
		if (close(pipe_fd[0]) == -1)
			ft_error("Input child failed closing the read fd pipe");
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1 || dup2(infile_fd, STDIN_FILENO) == -1
			|| dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_error("Infile fd creation or dup2 failed");
		if (close(infile_fd) == -1 || close(pipe_fd[1]) == -1)
			ft_error("Some fd close failed in the infile child proccess");
		ft_exec(argv[2], envp);
	}
}
