/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:14:08 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/22 19:05:25 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0')
		&& (s1[i] == s2[i]) && (i < n - 1))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
int	main(void)
{
	char	str1[] = "H0la.";
	char	str2[] = "Hola.";
	char	str3[] = "Adios.";
	char	str4[] = "Adios";
	char	str5[] = "Hey.";
	char	str6[] = "Hey-";
	char	str7[] = "01";
	char	str8[] = "0123";

	printf("%s %s = % d\n", str1, str2, ft_strncmp(str1, str2, 5*sizeof(char)));
	printf("%s %s = % d\n", str1, str2, ft_strncmp(str3, str4, 6*sizeof(char)));
	printf("%s %s = % d\n", str1, str2, ft_strncmp(str5, str6, 2*sizeof(char)));
	//strncmp deja de comparar después del primer NULL '\0' que encuentra.
	printf("%s %s = % d\n", str1, str2, ft_strncmp(str7, str8, 4*sizeof(char)));
	printf("%s %s = % d\n", str1, str2, ft_strncmp(str5, str6, 0*sizeof(char)));
	return(0);
}*/
