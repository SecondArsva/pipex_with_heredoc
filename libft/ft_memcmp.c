/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:04:44 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/29 00:18:23 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *) s1;
	ptr_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str0[] = "El miedo mata la mente.";
	char	str1[] = "El miedo ";

	int		arr0[] = { 0, 1, 22, 333};
	int		arr1[] = { 0, 1, 22};

	//printf("%i\n", ft_memcmp(str0, str1, 2*sizeof(char)));
	printf("Mía: %i\n", ft_memcmp(str0, str1, 9*sizeof(char)));
	printf("Original: %i\n", memcmp(str0, str1, 9*sizeof(char)));
	//printf("%i\n", ft_memcmp(str0, str1, 10*sizeof(char)));
	// Con está comparación hago que vaya más allá del '\0' del str0.
	//printf("%i\n", ft_memcmp(str0, str0, 50*sizeof(char)));

	//printf("\n");
	//printf("%i\n", ft_memcmp(arr0, arr1, 3*sizeof(int)));
	printf("Mía: %i\n", ft_memcmp(arr0, arr1, 4*sizeof(int)));
	printf("Original: %i\n", memcmp(arr0, arr1, 4*sizeof(int)));
	return (0);
}*/
