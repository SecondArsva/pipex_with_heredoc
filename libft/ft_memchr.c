/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:54:39 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/24 20:31:07 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "unistd.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	character;
	size_t			i;

	ptr_s = (unsigned char *) s;
	character = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (ptr_s[i] == character)
			return (&ptr_s[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "El miedo mata la mente.";
	char	c1 = 'i';

	int		arr1[] = { 0, 1, 20, 30};
	char	c2 = '2';

	printf("My ft_memchr: %s\n", ft_memchr(str1, c1, strlen(str1)*sizeof(char)));
	printf("Original memchr: %s\n", memchr(str1, c1, strlen(str1)*sizeof(char)));
	
	// incompatible pointer types passing 'int [4]' to parameter of type
	// 'const char *'
	printf("My ft_memchr: %s\n", ft_memchr(arr1, c2, strlen(arr1)*sizeof(int)));
	printf("Original ft_memchr: %s\n", memchr(arr1, c2, strlen(arr1)*sizeof(int)));
	return (0);
}*/
