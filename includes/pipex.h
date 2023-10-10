/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:57:14 by davidga2          #+#    #+#             */
/*   Updated: 2023/09/17 23:09:17 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

void	ft_error(char *str);
void	ft_cmd_error(char *cmd);
void	ft_infile_child(char **argv, char **envp, int *pipe_fd);
void	ft_outfile_child(char **argv, char **envp, int *pipe_fd);
char	**ft_get_paths(char **envp);
void	ft_pipex(char **argv, char **envp);
void	ft_exec(char *argv, char **envp);

#endif
