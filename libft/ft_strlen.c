/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:12:26 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/20 19:04:26 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	string1[4] = "Hola";
	char	string2[20];
	char	string3[5] = "Hola";

	printf("%zu\n", ft_strlen(string1));
	printf("%zu\n", ft_strlen(string2));
	printf("%zu\n", ft_strlen(string3));
	printf("%lu\n", strlen(string1));
	printf("%lu\n", strlen(string2));
	printf("%lu\n", strlen(string3));
	return (0);
}*/
