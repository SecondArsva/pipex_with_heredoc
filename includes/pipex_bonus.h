/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:57:14 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/12 18:29:32 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"

void	ft_error(char *str);
void	ft_cmd_error(char *cmd);
void	ft_infile_child(char **argv, char **envp, int *pipe_fd);
void	ft_middle_child(char *cmd_argv, char **envp, int *left, int *right);
void	ft_outfile_child_b(char **argv, int cmd, char **envp, int *pipe_fd);
char	**ft_get_paths(char **envp);
void	ft_pipex(char **argv, char **envp, int total_childs, int middle_childs);
int		ft_fork_manage(void);
void	ft_exec(char *argv, char **envp);

void	ft_pipe_manage(int *fd);
void	ft_pipe_close(int *fd);
void	ft_wait_childs(int total_childs);

void	ft_pipex_heredoc(char **argv, char **envp);
void	ft_heredoc_child(char **argv, char **envp, int *pipe);
void	ft_outfile_child_heredoc(char **argv, char **envp, int *pipe);

#endif
