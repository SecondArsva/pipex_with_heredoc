/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:58:19 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/09 23:19:01 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
/*
int	main(void)
{
	char	a = 'a';
	char	b = 98;
	char	z = 122;
	char	null = 0;
	char	zero = '0';
	char	exc = '!';
	char	dot = '.';
	char	star = '*';
	char	unkw = 126;

	printf("a: %c\n", ft_toupper(a));
	printf("b: %c\n", ft_toupper(b));
	printf("z: %c\n", ft_toupper(z));
	printf("null: %c\n", ft_toupper(null));
	printf("zero: %c\n", ft_toupper(zero));
	printf("exc: %c\n", ft_toupper(exc));
	printf("dot: %c\n", ft_toupper(dot));
	printf("star: %c\n", ft_toupper(star));
	printf("unkw: %c\n", ft_toupper(unkw));
	return (0);
}*/
