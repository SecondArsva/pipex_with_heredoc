/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:43:53 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/14 23:24:05 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0'
			&& i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[(i + j) - j]);
		j++;
		}
	i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	haystack1[] = "El miedo mata la mente.";
	char	needle0[5] = "";
	char	needle1[] = "miedo";
	char	needle2[] = "mente";
	char	needle3[] = " lasaña";
	
	printf("needle0: %s\n", ft_strnstr(haystack1, needle0, 5*sizeof(char)));
	printf("needle1: %s\n", ft_strnstr(haystack1, needle1, 7*sizeof(char)));
	printf("needle2: %s\n", ft_strnstr(haystack1, needle2, 23*sizeof(char)));
	printf("needle3: %s\n", ft_strnstr(haystack1, needle3, 50*sizeof(char)));
	return (0);
}*/
