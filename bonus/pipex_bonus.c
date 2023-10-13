/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:37:02 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/13 18:23:49 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

// Función encargada de esperar a tantos subprocesos hijos como el número
// entero que se reciba por el parámetro de la función. "waitpid(-1, NULL, 0)"
// espera a cualquier subproceso/hijo dentro de la totalidad de
// subprocesos/hijos en ejecución. Solo espera a uno dentro de todo el grupo,
// por lo que si queremos esperar a varios hijos deberá ejecutarse tantas veces
// como hijos a esperar, de hay que esté anidada en un bucle.
void	ft_wait_childs(int total_childs)
{
	while (total_childs > 0)
	{
		waitpid(-1, NULL, 0);
		total_childs--;
	}
}

// Función para la gestión de errores en la creación de un pipe.
// Permite ahorrar una línea a la hora de crear un pipe.
// Recibe por parámetro los 2 fd que se usarán para su vinculación y creación del pipe.
void	ft_pipe_manage(int *fd)
{
	if (pipe(fd) == -1)
		ft_error("fds linking at pipe creation has failed");
}

// Función encargada de cerrar ambos extremos del pipe recibido por parámetro.
// Usada principalmente en el proceso padre y creada para
// ahorrar líneas de código de cara a la Norma.
void	ft_pipe_close(int *fd)
{
	if (close(fd[0]) == -1)
		ft_error("Failure closing pipe_fd[0]");
	if (close(fd[1]) == -1)
		ft_error("Failure closing pipe_fd[1]");
}

// Como en el bonus se incluye el multi-pipe, hay un nuevo subproceso hijo
// encargado de comunicarse con dos pipes; recibiendo información de un pipe y
// volcando el resultado de su ejecución de subproceso en otro pipe con sus
// debidas redirecciones.
// Siempre se usarán tantos pipes menos 1 como comandos se hayan introducido,
// aunque realmente solo coexistirán dos pipes al mismo tiempo durante la
// ejecución del programa en caso de introducir más de 2 comandos debido al
// funcionamiento del hijo intermedio.
// Por ello el proceso padre necesita declarar dos variables dedicadas a la creación de
// los dos posibles pipes que coexistirán al mismo tiempo.
// En caso de haber multi-piping se hará uso del hijo intermedio tantas veces como
// hijos intermedios haya. Esto se calcula restándole 5 al número total de argumentos.
// El número total de hijos serán los argumentos menos 3.
// En caso de necesitar multi-piping se creará el segundo pipe, se ejecutará la función
// del hijo intermedio, se cerrará el primer pipe y el segundo pipe pasará a ser el
// primero para que el siguiente hijo intermedio o el hijo final lo traten debidamente.
// middle_childs es el contador de hijos intermedios que han de ejecutarse.
// cmd_count es la posición del argumento a usar como comando dentro de los hijos
// intermedios e hijo final.
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
		ft_pipe_close(left);
		middle_childs--;
		cmd_count++;
		left[0] = right[0];
		left[1] = right[1];
	}
	ft_outfile_child_b(argv, cmd_count, envp, left);
	ft_pipe_close(left);
	ft_wait_childs(total_childs);
}

// El main se encarga de llamar a una función u otra según se use
// single-pipe o multi-pipes con ft_pipex, en su defecto el heredoc,
// que solo usa singe-pipe según el ejemplo del subject con ft_pipe_heredoc.
//
// Estructura en la ejecución con un solo pipe:
// 					"./pipex_bonus infile "cmd1" "cmd2" outfile"
// Estructura en la ejecución del multi-pipe:
//					"./pipex_bonus infile "cmd1" "cmd2" "cmd3" "cmd(...)" outfile"
// Estructura de la ejecución del heredoc:
// 					"./pipex_bonus here_doc LIMITER "cmd1" "cmd2" outfile"
int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
	{
		if (argc == 6 && !ft_strncmp(argv[1], "here_doc", 8))
			ft_pipex_heredoc(argv, envp);
		else
			ft_pipex(argv, envp, argc - 3, argc - 5);
	}
	else
		return (ft_printf_error("pipex: invalid arguments\n"), 1);
	return (0);
}
