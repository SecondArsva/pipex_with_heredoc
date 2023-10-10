/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:13 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/15 16:49:40 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
	b = 'c';
	x = '~';
	z = '[';
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", ft_isalpha(b));
	printf("%d\n", ft_isalpha(x));
	printf("%d\n", ft_isalpha(z));
	printf("%d\n", isalpha(a));
	printf("%d\n", isalpha(b));
	printf("%d\n", isalpha(x));
	printf("%d\n", isalpha(z));
	return (0);
}*/
