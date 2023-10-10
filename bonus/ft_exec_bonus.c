/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:05:27 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/04 05:27:05 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// If the argument corresponding to a command does not contain a path,
// the path will be taken from the binary directories housed in the PATH
// environment variable.
int	ft_path_type(char *cmd_argv)
{
	int	path_type;

	path_type = 0;
	if (ft_strncmp(cmd_argv, "/", 1) == 0 || ft_strncmp(cmd_argv, "./", 2) == 0
		|| ft_strncmp(cmd_argv, "../", 3) == 0)
		path_type = 1;
	else
		path_type = 2;
	return (path_type);
}

// Looks for the PATH in the env and splits the binaries.
// If no PATH exists, it should exit.
// The "if (!envp[i])" avoids the segfault
// in case the PATH variable does not exist.
char	**ft_get_paths(char **envp)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = NULL;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		ft_error("PATH dont exits in the enviroment");
	matrix = ft_split(&envp[i][5], ':');
	if (!matrix)
		ft_error("Binaries matrix reserve failed");
	return (matrix);
}

// This function makes use of the PATH environment variable to obtain the
// correct binary directory in which the command is located.
char	*ft_get_correct_binary_path(char *cmd, char **envp)
{
	char	*correct_path;
	char	**binaries;
	int		i;

	correct_path = NULL;
	binaries = ft_get_paths(envp);
	i = 0;
	if (!binaries)
		ft_error("Binaries matrix creation failed");
	while (binaries[i])
	{
		correct_path = ft_strdoublejoin(binaries[i], "/", cmd);
		if (!correct_path)
			ft_error("Double join failed");
		if (access(correct_path, X_OK) == 0)
			return (correct_path);
		i++;
	}
	ft_cmd_error("Command not found");
	return (NULL);
}

// Splits the command argument and depending on the type of route,
// execute it in one way or another.
void	ft_exec(char *cmd_argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(cmd_argv, ' ');
	if (!cmd)
		ft_error("Command matrix creation failed");
	if (ft_path_type(cmd_argv) == 1)
		path = cmd[0];
	else if (ft_path_type(cmd_argv) == 2)
		path = ft_get_correct_binary_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
		ft_error("Command execution failed");
}
