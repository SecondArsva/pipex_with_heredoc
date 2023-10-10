/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:32:52 by davidga2          #+#    #+#             */
/*   Updated: 2023/09/11 11:31:34 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	unsigned int	i;

	if (dst == NULL && src == NULL)
		return (0);
	ptr_dst = (unsigned char *) dst;
	ptr_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	source[20] = "Hola.";
	char	destination[20] = "Ciao, bella.";
	int		arraysrc[4] = {0, 1, 2, 3333};
	int		arraydst[20] = {4, 55, 666, 7, 8, 9};
	int		slot = 3;
	
	printf("Source: %s\n", source);
	printf("Before Destination: %s\n", destination);
	printf("ft_memcpy: %s\n", ft_memcpy(destination, source, 4*sizeof(char)));
	printf("After Destination: %s\n", destination);
	printf("\n");
	printf("Source Array: %d\n", arraysrc[slot]);
	printf("Before Destination Array: %d\n", arraydst[slot]);
	printf("ft_memcpt: %s\n", ft_memcpy(arraydst, arraysrc, 4*sizeof(int)));
	printf("After Destination Array: %d\n", arraydst[slot]);
	return (0);
}*/
