/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:54:55 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/16 00:01:38 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char			*ptr_str;
	unsigned char	character;
	unsigned int	i;

	ptr_str = (char *) str;
	character = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		ptr_str[i] = character;
		i++;
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{
	char	string1[50] = "Hola, amigos del Youtube.";
	char	string2[50] = "El miedo mata la mente.";
	//char	string3[10] = "0123456789";
	int		array4[] = {6, 6, 6};
	char	character1 = '*';
	char	character2 = '$';
	unsigned char	character3 = 97;

	printf("1 Before: %s\n", string1);
	printf("1 %s\n", ft_memset(string1 + 6, character1, 4*sizeof(char)));
	printf("1 After: %s\n", string1);
	printf("\n");
	printf("2 Before: %s\n", string2);
	printf("2 %s\n", ft_memset(string2, character2, 2*sizeof(char)));
	printf("2 After: %s\n", string2);
	printf("\n");

	// Este no compila porque originalmente la función memset
	// no rellena más del tamaño total de un string.
	//printf("3 Before: %s\n", string3);
	//printf("3 ft_memset(): %s\n", memset(string3 + 10, character3, 10));
	//printf("3 After: %s\n", string3);
	//printf("\n");
	
	// Este compila ya que mediante el uso de argumentos en el main
	// el compilador no sabe si vamos a introducir un string con menos
	// carracteres de los que indiquemos que rellene.
	if (argc > 1)
	{
	printf("\n");
	printf("Argument Before: %s\n", &argv[1][0]);
	printf("%s\n", ft_memset(&argv[1][0] + 10, character3, 40*sizeof(char)));
	printf("Argument After: %s\n", &argv[1][0]);
	}
	
	// Con esto printea números de más aún indicando que solo muestre un
	// caracter, ya que como las variables de tipo "int" se componen de
	// 4 bytes, en lugar de las variables de tipo "char" que se componen
	// de solo 1 byte (por eso se usa sizeof), al poner un array de tipo
	// "int" modifica byte a byte (que es lo que hace  memset "writes len
	// bytes of value c". Ver el man memset) y aunque parezca que está mal,
	// está bien.
	printf("\n");
	printf("4 Before: %d\n", array4[0]);
	printf("4 %s\n", ft_memset(array4, character2, 2*sizeof(int)));
	printf("4 After: %d\n", (int) array4[0]);
	return (0);
}*/
