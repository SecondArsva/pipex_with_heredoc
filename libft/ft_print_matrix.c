/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:26:03 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/23 05:16:41 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(char **matrix, char *var_name)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	if (!matrix)
		return ;
	if (!var_name)
		var_name = "";
	while (matrix[max])
		max++;
	while (i++ < max)
		ft_printf("%s[%i] = %s\n", var_name, i - 1, matrix[i - 1]);
}
