/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:21:44 by davidga2          #+#    #+#             */
/*   Updated: 2023/09/25 20:48:47 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_error(char *str)
{
	perror(str);
	exit(errno);
}

void	ft_cmd_error(char *cmd)
{
	ft_printf_error("%s", cmd);
	ft_printf_error(": command not found\n");
	exit(127);
}
