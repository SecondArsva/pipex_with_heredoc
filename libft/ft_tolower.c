/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:20:39 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/09 23:28:29 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*
int	main(void)
{
	char	A = 'A';
	char	B = 66;
	char	Z = 90;
	char	null = 0;
	char	zero = '0';
	char	exc = '!';
	char	dot = '.';
	char	star = '*';
	char	unkw = 126;

	printf("A: %c\n", ft_tolower(A));
	printf("B: %c\n", ft_tolower(B));
	printf("Z: %c\n", ft_tolower(Z));
	printf("null: %c\n", ft_tolower(null));
	printf("zero: %c\n", ft_tolower(zero));
	printf("exc: %c\n", ft_tolower(exc));
	printf("dot: %c\n", ft_tolower(dot));
	printf("star: %c\n", ft_tolower(star));
	printf("unkw: %c\n", ft_tolower(unkw));
	return (0);
}*/
