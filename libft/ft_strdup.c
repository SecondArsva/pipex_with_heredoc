/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:22:53 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/27 19:05:25 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new_ptr;

	i = 0;
	new_ptr = malloc(ft_strlen(s1) + 1);
	if (!new_ptr)
		return (0);
	while (s1[i] != '\0')
	{
		new_ptr[i] = s1[i];
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}
/*
int	main(void)
{
	char	str[] = "El miedo mata la mente.";
	char	*duplicate_str = ft_strdup(str);

	printf("%s\n", duplicate_str);
	return (0);
}*/
