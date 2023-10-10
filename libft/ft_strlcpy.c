/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:07:39 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/20 19:37:04 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"
/*
size_t	ft_strlen(const char *ptr_str)
{
	size_t	i;

	i = 0;
	while (ptr_str[i] != '\0')
	{
		i++;
	}
	return (i);
}
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	dst1[50] = "0123456789";
	char	src1[50] = "ABCDEFGHIJ";

	printf("%s\n", src1);
	printf("%s\n", dst1);
	printf("%lu\n", strlcpy(dst1, src1, ft_strlen(dst1)*sizeof(char)));
	printf("%s\n", src1);
	printf("%s\n", dst1);
	return (0);
}*/
