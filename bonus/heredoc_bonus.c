/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:52:58 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/13 03:44:08 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

// Documenta esto, men.  Añade protecciones al crear o borrar el heredoc, gracias vicmarti.
int	ft_heredoc(char **argv)
{
	int		tmp_file_fd;
	char	*file_name;
	char	*writed_line;
	char	*limiter;

	file_name = ".heredoc";
	limiter = argv[2];
	tmp_file_fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 0);
		writed_line = get_next_line(STDIN_FILENO);
		if (!writed_line)
			break ;
		if (!ft_strncmp(writed_line, limiter, ft_strlen(limiter)))
			break ;
		write(tmp_file_fd, writed_line, ft_strlen(writed_line));
		free(writed_line);
	}
	close(tmp_file_fd);
	tmp_file_fd = open(file_name, O_RDONLY);
	return (tmp_file_fd);
}

void	ft_heredoc_child(char **argv, char **envp, int *pipe)
{
	pid_t	pid;
	int		heredoc_fd;
	
	pid = ft_fork_manage();
	if (!pid)
	{
		heredoc_fd = ft_heredoc(argv);
		close(pipe[0]);
		dup2(heredoc_fd, STDIN_FILENO);
		dup2(pipe[1], STDOUT_FILENO);
		close(heredoc_fd);
		close(pipe[1]);
		ft_exec(argv[3], envp);
	}
	ft_wait_childs(1);
}

void	ft_outfile_child_heredoc(char **argv, char **envp, int *pipe)
{
	pid_t	pid;
	int		outfile_fd;

	pid = ft_fork_manage();
	if (!pid)
	{
		unlink("./.heredoc");
		outfile_fd = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(pipe[1]);
		dup2(pipe[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(pipe[0]);
		close(outfile_fd);
		ft_exec(argv[4], envp);
	}
}

void	ft_pipex_heredoc(char **argv, char **envp)
{
	int	pipe[2];

	ft_pipe_manage(pipe);
	ft_heredoc_child(argv, envp, pipe);
	ft_outfile_child_heredoc(argv, envp, pipe);
	ft_pipe_close(pipe);
	ft_wait_childs(1);
}
