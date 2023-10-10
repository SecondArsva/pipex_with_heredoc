/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:59:27 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/14 22:51:03 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <strings.h>
#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	char			*ptr_str;
	unsigned int	i;

	ptr_str = (char *) str;
	i = 0;
	while (i < n)
	{
		ptr_str[i] = '\0';
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	string1[50] = "Hola, amigos del Youtube.";
	char	string2[] = "Hola";
	int		array3[3] = {6, 6, 6};

	printf("1 Before: %s\n", string1);
	printf("1 %s\n", ft_bzero(string1, 4*sizeof(char)));
	printf("1 After: %s\n", string1);
	printf("\n");
	printf("2 Before: %s\n", string2);
	printf("2 %s\n", ft_bzero(string2 + 1, 2*sizeof(char)));
	printf("2 After: %s\n", string2);
	printf("\n");
	printf("2 Before: %d\n", array3[0]);
	printf("2 %s\n", ft_bzero(array3, 1*sizeof(int)));
	printf("2 After: %d\n", array3[0]);
}*/
