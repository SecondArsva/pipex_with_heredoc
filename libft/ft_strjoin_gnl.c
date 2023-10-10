/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:55:35 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/09 00:12:45 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new_ptr;
	size_t	i;
	size_t	j;

	new_ptr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new_ptr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new_ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_ptr[i + j] = s2[j];
		j++;
	}
	return (new_ptr);
}
