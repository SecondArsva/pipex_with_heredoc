/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:04:25 by davidga2          #+#    #+#             */
/*   Updated: 2023/09/11 04:05:19 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//De esta forma se incluyen librerías propias.
//Entre las comillas se establece la ruta y archivo de la librería.
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	unsigned const char	*ptr_src;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (0);
	ptr_dst = (unsigned char *) dst;
	ptr_src = (unsigned const char *) src;
	i = 0;
	if (dst > src)
	{
		while (++i <= len)
			ptr_dst[len - i] = ptr_src[len - i];
	}
	else
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main()
{
	char	source[20] = "Hola.";
	char	destination[20] = "Ciao, bella.";
	int		arraysrc[4] = {0, 1, 97, 3333};
	int		arraydst[20] = {4, 55, 666, 7, 8, 9};
	int		slot = 2;
	char 	jyur[50] = "El miedo mata la mente.";

	printf("Mi ft_memmove\n");
	printf("Source: %s\n", source);
	printf("Before Destination: %s\n", destination);
	printf("ft_memcpy: %s\n", ft_memmove(destination, source + 1, 4*sizeof(char)));
	printf("After Destination: %s\n", destination);
	printf("\n");
	printf("Source Array: %d\n", arraysrc[slot]);
	printf("Before Destination Array: %d\n", arraydst[slot]);
	printf("ft_memcpt: %s\n", ft_memmove(arraydst, arraysrc, 3*sizeof(int)));
	printf("After Destination Array: %d\n", arraydst[slot]);
	printf("\n");
	// Hace lo mismo que memcpy, WTF?
	// pgomez-s usa una variable tmp o aux para primero copiar el src a ella.
	// No entiendo muy bien para que.
	// jyurrita tip:
	// Prueba a introducir un mismo string como dst y src a la vez,
	// estando el dst desplazado algún caracter hacia delante y mira qué pasa.
	// ade-kint me ha comentado que le han dicho que la variable tmp/aux se
	// usa para evitar que se modifique el string src. Tiene sentido tras lo
	// de jyurrita...
	printf("Before jyur: %s\n", jyur);
	printf("move: %s\n", ft_memmove(jyur + 3, jyur, 300*sizeof(char)));
	printf("After jyur: %s\n", jyur);
	// Al ejecutar esto con el mismo código de memcopy en mi función
	// de ft_memmove sale esto: "jyur: El El El El El El El El�".
	// Si ejecuto la función memmove original con esto sale:
	// zsh: illegal hardware instruction  ./a.out.
	// Por eso será necesario el string tmp/aux.
	// Al añadir el tmp_str y copiarle el src en unn while, para luego copiar
	// el tmp_str al dst no da error y aparentemente va perfecto.
	return (0);
}*/
