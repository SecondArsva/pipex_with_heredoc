/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:41:55 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/30 19:59:39 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	character;

	i = 0;
	character = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == character)
			return ((char *) &s[i]);
		i++;
	}
	if (character == '\0')
		return ((char *) &s[i]);
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "El miedo mata la mente.";
	char	locate1 = 'm';
	char	locate2 = '\0';
	char	locate3 = 'z';

	printf("%s\n", ft_strchr(str1, locate1));
	printf("%s\n", ft_strchr(str1, locate2));
	printf("%s\n", ft_strchr(str1, locate3));
	return (0);
}*/
