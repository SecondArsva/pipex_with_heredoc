/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:37:51 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/15 16:46:25 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isprint('A'));
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", ft_isprint(3));
	printf("%d\n", ft_isprint(127));
	printf("%d\n", isprint('2'));
	printf("%d\n", isprint('!'));
	printf("%d\n", isprint(13));
	printf("%d\n", isprint(127));
	return (0);
}*/
