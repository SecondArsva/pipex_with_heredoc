/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:58:36 by davidga2          #+#    #+#             */
/*   Updated: 2023/04/06 00:17:16 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*new_ptr;

	j = 0;
	if (!s)
		return (0);
	if (start < ft_strlen(s))
	{
		if (len > ft_strlen(s) - start)
			len = ft_strlen(s) - start;
		new_ptr = ft_calloc(len + 1, sizeof(char));
		if (!new_ptr)
			return (0);
		while (s[start] != '\0' && j < len)
		{
			new_ptr[j] = s[start + j];
			j++;
		}
		new_ptr[j] = '\0';
		return (new_ptr);
	}
	new_ptr = ft_calloc(1, sizeof(char));
	if (!new_ptr)
		return (0);
	return (new_ptr);
}
/*
int	main(void)
{
	//char	str[] = "El miedo mata la mente.";
	//int		start0 = 4;
	//int		start1 = 10;
	//int		start2 = 1;
	//int		start3 = 50;
	//int		start4 = 1;
	//int		start5 = 0;
	//size_t	len0 = 5;
	//size_t	len1 = 4;
	//size_t	len2 = 50;
	//size_t	len3 = 5;
	//size_t	len4 = 0;
	//size_t	len5 = 2;

	// Debería salir "mente".
	//printf("%s\n", ft_substr(str, start0, len0));
	// Debería salir "mata".
	//printf("%s\n", ft_substr(str, start1, len1));
	// Debería copiar todo, parando en NULL de str a través del *s.
	//printf("%s\n", ft_substr(str, start2, len2));
	// Debería irse hasta el final y, por ello, no copiar nada.
	//printf("%s\n", ft_substr(str, start3, len3));
	// Debería no copiar nada al ponerle en len un 0.
	//printf("%s\n", ft_substr(str, start4, len4));
	// Debería copiar ni el "El", ya que trabajamos solo con positivos.
	//printf("%s\n", ft_substr(str, start5, len5));
	//Prueba en a que me falla paco:
	printf("%s\n", ft_substr("hola", 0, 9223372036854775808));
	return (0);
}*/
