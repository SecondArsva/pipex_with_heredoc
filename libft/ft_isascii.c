/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:30 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/15 16:48:25 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	//char	eñe;

	//eñe = 'ñ';
	printf("%d\n", ft_isascii(0));
	printf("%d\n", ft_isascii(127));
	//printf("%d\n", ft_isascii(eñe));
	printf("%d\n", ft_isascii('A'));
	printf("%d\n", ft_isascii(' '));
	printf("%d\n", isascii(0));
	printf("%d\n", isascii(127));
	//printf("%d\n", isascii(eñe));
	printf("%d\n", isascii('A'));
	printf("%d\n", isascii(' '));
}*/
