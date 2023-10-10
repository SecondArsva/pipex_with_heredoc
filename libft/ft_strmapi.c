/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:46:46 by davidga2          #+#    #+#             */
/*   Updated: 2023/04/05 22:10:12 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*new_ptr;

	i = 0;
	len = ft_strlen(s);
	new_ptr = (char *) malloc(len + 1 * sizeof(char));
	if (!new_ptr)
		return (0);
	while (i < len)
	{
		new_ptr[i] = f(i, s[i]);
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}
/*
int	main(void)
{
	char	str0[] = "El miedo mata la mente.";
	void	(*funct) (char);

	*funct = ft_toupper;
	printf("ft_strmapi result: %s\n", ft_strmapi(str0, ));
	return (0);
}*/
