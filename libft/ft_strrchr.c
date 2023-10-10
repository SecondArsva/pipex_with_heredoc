/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:23:05 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/28 22:57:51 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	character;

	i = ft_strlen(s);
	character = (char) c;
	while (i >= 0)
	{
		if (s[i] == character)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "El miedo mata la mente.";
	char	locate1 = 'm';
	char	locate2 = '\0';
	char	locate3 = 'z';

	printf("%s\n", ft_strrchr(str1, locate1));
	printf("%s\n", ft_strrchr(str1, locate2));
	printf("%s\n", ft_strrchr(str1, locate3));
	return (0);
}*/
