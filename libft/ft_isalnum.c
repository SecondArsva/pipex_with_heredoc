/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:29:26 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/15 19:29:31 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('b'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", ft_isalnum('-'));
	printf("%d\n", isalnum('A'));
	printf("%d\n", isalnum('b'));
	printf("%d\n", isalnum('1'));
	printf("%d\n", isalnum('-'));
	return (0);
}*/
