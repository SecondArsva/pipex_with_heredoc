/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:57:14 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/05 01:30:39 by davidga2         ###   ########.fr       */
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
void	ft_exec(char *argv, char **envp);

#endif
