/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:38:50 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/23 23:10:29 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (dst == 0)
		return (src_len);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char	dst0[] = "";
	char	dst1[50] = "0123456789";
	char	src1[50] = "ABCDEFGHIJ";
	// Variable que determina cuanto se va a concatenar. Ya que quiero copiar todo,
	// he de poner el total de la suma de las dos cadenas de caracteres más un
	// espacio estra para el null.
	int		size1 = ft_strlen(dst1) + ft_strlen(src1) + 1;
	int		size2 = 5;


	printf("%s\n", src1);
	printf("%s\n", dst1);
	// En strlcat el dstsize no tiene que ser un strlen de dst,
	// ya que dstsize ha de ser mayor que el total de caracteres
	// encontrables por la función strlen(dst) para que pueda concatenar
	// lo que le entre por el src. Sino, aún estando bien, no concatena
	// ya que le especificamos que pare cuando llegue al final de dst.
	printf("Size: %i | %lu\n", size1, strlcat(dst1, src1, size1*sizeof(char)));
	printf("Size: %i | %lu\n", size2, strlcat(dst1, src1, size2*sizeof(char)));
	printf("dst0[] = empty | %lu\n", strlcat(dst0, src1, size2*sizeof(char)));
	printf("%s\n", src1);
	printf("%s\n", dst1);
	return (0);
}*/
