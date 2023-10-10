/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdoublejoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:56:25 by davidga2          #+#    #+#             */
/*   Updated: 2023/10/09 20:29:39 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdoublejoin(char *str1, char *str2, char *str3)
{
	char	*join;
	char	*doublejoin;

	join = NULL;
	doublejoin = NULL;
	if (!str1 || !str2 || !str3)
		return (0);
	join = ft_strjoin(str1, str2);
	if (!join)
		return (0);
	doublejoin = ft_strjoin(join, str3);
	if (!doublejoin)
	{
		free(join);
		return (0);
	}
	free(join);
	return (doublejoin);
}
/*
int	main(void)
{
	char *str1 = "/bin";
	char *str2 = "/";
	char *str3 = "cat";
	ft_printf("%s\n", ft_strdoublejoin(str1, str2, str3));
	return (0);
}*/
