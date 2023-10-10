/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:10:21 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/15 16:47:13 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char	a;
	char	b;
	char	x;
	char	z;

	a = 'A';
	b = '+';
	x = '2';
	z = '8';
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit(b));
	printf("%d\n", ft_isdigit(x));
	printf("%d\n", ft_isdigit(z));
	printf("%d\n", isdigit('9'));
	printf("%d\n", isdigit('&'));
	printf("%d\n", isdigit(a));
	printf("%d\n", isdigit(b));
	printf("%d\n", isdigit(x));
	printf("%d\n", isdigit(z));
	printf("%d\n", isdigit('9'));
	printf("%d\n", isdigit('&'));
	return (0);
}*/
