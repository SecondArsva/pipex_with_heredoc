/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:52:58 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/17 20:50:31 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_heredoc_write_loop(char *limiter, int heredoc_fd)
{
	char *writed_line;

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
	free(limiter);
}

// Documenta esto, men.
// Añade protecciones al crear o borrar el heredoc, gracias vicmarti.
//
// apped
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
	close(heredoc_fd);
	heredoc_fd = open(".heredoc", O_RDONLY);
	return (heredoc_fd);
}

// Función dedicada al primer subproceso/hijo, encargado de crear el archivo
// temporal en el que se replicará el funcionamiento del heredoc a modo de
// infile.
// Se crea el subproceso y dentro del mismo se asigna el fd del archivo
// temporal del heredoc a la variable heredoc_fd mediante la función
// ft_heredoc.
// Se cierra el fd del extremo del pipe con el que no interactua.
// Se redireccionan los fd in y out con el fd del heredoc y el extremo de
// escritura del pipe respectivamente y después se cierran. Finalmente se
// ejecuta el comando introducido.
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

// Función dedicada al subproceso/hijo final.
// Crea y gestiona el subproceso.
// Dentro del subproceso:
// Borra el archivo oculto dedicado al heredoc para evitar tener archivos
// basura tras la ejecución del programa.
// Crea (con open) un archivo en el que volcar el resultado de la ejecución
// del programa asociado al comando introducido, o lo abre en caso de existir.
// Cierra el extremo del pipe con el que no interactua.
// Redirecciona los fd de entrada y salida al fd extremo del lectura del pipe
// y el fd del outfile respectivamente.
// Cierra los fd por los que se "dupeado".
// Ejecuta el comando introducido mediante ft_exec.
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

// Como en el subject no se pone un ejemplo usando multi-piping, en el bonus
// del heredoc solo uso un pipe.
// Desde el proceso padre se crea el pipe y se llaman a las funciones que
// ejecutarán a los hijos(subprocesos). Después se cierra el pipe,
// no por gusto ni una buena práctica, sino porque si no lo cerramos no va.
// Y espera a que termine la ejecución del último hijo.
void	ft_pipex_heredoc(char **argv, char **envp)
{
	int	pipe[2];

	ft_pipe_manage(pipe);
	ft_heredoc_child(argv, envp, pipe);
	ft_outfile_child_heredoc(argv, envp, pipe);
	ft_pipe_close(pipe);
	ft_wait_childs(1);
}
