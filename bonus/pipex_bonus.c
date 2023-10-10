/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:37:02 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/05 02:49:52 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_wait_childs(int total_childs)
{
	while (total_childs > 0)
	{
		waitpid(-1, NULL, 0);
		total_childs--;
	}
}

void	ft_pipe_manage(int *fd)
{
	if (pipe(fd) == -1)
		ft_error("fds linking at pipe creation has failed");
}

void	ft_pipe_closing(int *fd)
{
	if (close(fd[0]) == -1)
		ft_error("Failure closing pipe_fd[0]");
	if (close(fd[1]) == -1)
		ft_error("Failure closing pipe_fd[1]");
}

void	ft_pipex(char **argv, char **envp, int total_childs, int middle_childs)
{
	int		left[2];
	int		right[2];
	int		cmd_count;

	cmd_count = 3;
	ft_pipe_manage(left);
	ft_infile_child(argv, envp, left);
	while (middle_childs > 0)
	{
		ft_pipe_manage(right);
		ft_middle_child(argv[cmd_count], envp, left, right);
		ft_pipe_closing(left);
		middle_childs--;
		cmd_count++;
		left[0] = right[0];
		left[1] = right[1];
	}
	ft_outfile_child_b(argv, cmd_count, envp, left);
	ft_pipe_closing(left);
	ft_wait_childs(total_childs);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		ft_pipex(argv, envp, argc - 3, argc - 5);
	else
		return (ft_printf_error("pipex: invalid arguments\n"), 1);
	return (0);
}
