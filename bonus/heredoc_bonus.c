/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:52:58 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/17 23:59:29 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_heredoc_write_loop(char *limiter, int heredoc_fd)
{
	char	*writed_line;

	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		writed_line = get_next_line(STDIN_FILENO);
		if (!writed_line)
			break ;
		if (!ft_strncmp(writed_line, limiter, ft_strlen(limiter)))
		{
			free(writed_line);
			break ;
		}
		write(heredoc_fd, writed_line, ft_strlen(writed_line));
		free(writed_line);
	}
}

int	ft_heredoc(char **argv)
{
	int		heredoc_fd;
	char	*limiter;

	limiter = ft_strjoin(argv[2], "\n");
	if (!limiter)
		ft_error("Limiter processing has failed");
	heredoc_fd = open(".heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (heredoc_fd == -1)
		ft_error("Failure opening the temporal file used in heredoc");
	ft_heredoc_write_loop(limiter, heredoc_fd);
	free(limiter);
	close(heredoc_fd);
	heredoc_fd = open(".heredoc", O_RDONLY);
	return (heredoc_fd);
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
		if (unlink("./.heredoc") == -1)
			ft_error("Failure erasing the temporal file used in heredoc");
		outfile_fd = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (outfile_fd == -1)
			ft_error("Last child failed open the outfile");
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
