/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:17:46 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/21 19:43:02 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrixdup(char **original)
{
	char	**duplicate;
	size_t	i;

	i = 0;
	if (!original)
		return (0);
	while (original[i])
		i++;
	duplicate = ft_calloc(i + 1, sizeof(char **));
	if (!duplicate)
		return (0);
	i = 0;
	while (original[i])
	{
		duplicate[i] = ft_substr(original[i], 0, -1);
		if (!duplicate[i])
			return (ft_free_matrix(duplicate), NULL);
		i++;
	}
	return (duplicate);
}
/*
int	main(void)
{
	char	*str = "123\n456\n789";
	char	**original = ft_split(str, '\n');
	char	**duplicate;
	
	duplicate = ft_matrixdup(original);
	ft_printf("dup[0] = %s\n", duplicate[0]);
	ft_printf("dup[1] = %s\n", duplicate[1]);
	ft_printf("dup[2] = %s\n", duplicate[2]);
	return (0);
}*/
