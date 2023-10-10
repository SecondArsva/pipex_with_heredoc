/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:12:07 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/08 23:18:32 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Determines how many segments are in the string.
static size_t	ft_n(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!s[0])
		return (0);
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			|| (s[i] != c && i == 0))
			n++;
	i++;
	}
	return (n);
}

// This "free" function frees from memory before the last substr in case
// it failed, because substr is protected.
// So if we free from the input value of "i" without subtracting one from
// it before freeing, we are trying to free something that doesn't exist.
static void	ft_free(char **matrix, size_t i)
{
	while (i)
	{
		i--;
		free(matrix[i]);
	}
	free(matrix);
}

// Wake up, Neo... The Matrix has you...
// This function creates the matrix: the array of pointers
// and its pointered content of each one, the substrings.
static char	**ft_matrix(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	**matrix;

	i = 0;
	start = 0;
	matrix = (char **) malloc((n + 1) * sizeof(char *));
	if (!matrix)
		return (0);
	while (i < n)
	{
		len = 0;
		while (s[start] == c && s[start] != '\0')
			start++;
		while (s[start + len] != c && s[start + len] != '\0')
			len++;
		matrix[i] = ft_substr(s, start, len);
		if (!matrix[i])
			return (ft_free(matrix, i), NULL);
		start = start + len;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**matrix;

	if (!s)
		return (0);
	n = ft_n(s, c);
	matrix = ft_matrix(s, c, n);
	return (matrix);
}
/*
int	main(void)
{
//	char	str0[] = "El miedo mata la mente. ";
//	char	str1[] = "";
//	char	str2[] = "NoSpaces";
//	char	str3[] = " PreSpace";
//	char	str4[] = "PostSpace ";
//	char	str5[] = "          ";
//	
//	char	str6[] = "      ALotOfSpaces     ";
//	char	split0 = ' ';
//
//	char	paco[] = "lorem ipsum dolor sit amet. Suspendisse";
//
//	printf("\nstr0: '%s'\n", str0);
//	ft_split(str0, split0);
//	printf("\nstr1: '%s'\n", str1);
//	ft_split(str1, split0);
//	printf("\nstr2: '%s'\n", str2);
//	ft_split(str2, split0);
//	printf("\nstr3: '%s'\n", str3);
//	ft_split(str3, split0);
//	printf("\nstr4: '%s'\n", str4);
//	ft_split(str4, split0);
//	printf("\nstr5: '%s'\n", str5);
//	ft_split(str5, split0);
//
//	printf("\nstr6: '%s'\n", str6);
//	ft_split(str6, split0);
//
//	printf("\npaco: '%s'\n", paco);
//	ft_split(paco, split0);
//	printf("\n");

	char	paco_strict[] = "hello! jajaja i asas asas";
	char	dlimit = ' ';
	printf("\npaco_strict: '%s' | dlimit: %d\n", paco_strict, dlimit);
	ft_split(paco_strict, dlimit);

//	size_t i = 0;
//	while (ft_split(str2, split0)[i])
//	{
//		printf("Matrix[%lu] substring: '%s'\n", i, ft_split(str2, split0)[i]);
//		i++;
//	}
//	char str[] = "hola";
//	i = 0;
//	while (i < 10)
//		printf("%c\n", str[i++]);
	return (0);
}*/
