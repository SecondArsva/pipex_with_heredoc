/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:36:54 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/08 23:18:02 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digitcounter(long int n)
{
	size_t	digits;

	if (n <= 0)
		digits = 1;
	else
	{
		digits = 0;
		n = n * 1;
	}
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t		len;
	size_t		isneg;
	char		*new_ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_digitcounter(n);
	isneg = 0;
	new_ptr = malloc((len + 1) * sizeof(char));
	if (!new_ptr)
		return (0);
	if (n < 0)
	{
		new_ptr[0] = '-';
		n = n * -1;
		isneg = 1;
	}
	new_ptr[len] = 0;
	while (len > (0 + isneg))
	{
		new_ptr[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (new_ptr);
}
/*
int	main(void)
{	
	int	n0 = -2147483648;
	int	n1 = -123456;
	int	n2 = 123;
	int	n3 = 0;
	
	printf("\n");
	printf("n0 = %i | ft_itoa: %s\n", n0, ft_itoa(n0));
	printf("\n");
	printf("n1 = %i | ft_itoa: %s\n", n1, ft_itoa(n1));
	printf("\n");
	printf("n2 = %i | ft_itoa: %s\n", n2, ft_itoa(n2));
	printf("\n");
	printf("n3 = %i | ft_itoa: %s\n", n3, ft_itoa(n3));
	printf("\n");
	
	printf("%s\n", ft_itoa((-2147483647 -1)));
	printf("%s\n", ft_itoa(0));
	printf("\n");
	return (0);
}*/
