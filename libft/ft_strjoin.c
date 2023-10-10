/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:00:44 by davidga2          #+#    #+#             */
/*   Updated: 2023/09/11 04:07:05 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_ptr = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!new_ptr)
		return (0);
	ft_strlcpy(new_ptr, s1, s1_len + 1);
	ft_strlcat(new_ptr + s1_len, s2, s2_len + 1);
	return (new_ptr);
}
/*
int	main(void)
{
	char	str1[] = "El miedo";
	char	str2[] = " mata la mente.";

	printf("%s\n", ft_strjoin(str1, str2));
	return (0);
}*/
