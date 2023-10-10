/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:22:14 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/31 19:25:39 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*new_ptr;

	i = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	new_ptr = ft_substr(s1, i, (j + 1) - i);
	return (new_ptr);
}
/*
int main(void)
{
	char	str0[] = " \nHola \n mundo! \n";
	char	str1[] = " \n";
	char	*aux;

	aux = ft_strtrim(str0, str1);
	printf("%s\n", aux);
//	free(aux);
	system ("leaks -q a.out");
	return (0);
}*/
