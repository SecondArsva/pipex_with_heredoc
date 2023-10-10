/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:27:04 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/26 23:44:00 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_count_error(char c, int *ctr)
{
	write (2, &c, 1);
	(*ctr)++;
}

void	ft_putstr_count_error(char *s, int *ctr)
{
	size_t	i;

	if (!s)
	{
		*ctr += write(2, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_count_error(s[i], ctr);
		i++;
	}
}

void	ft_putnbr_count_error(int n, int *ctr)
{
	if (n == -2147483648)
		ft_putstr_count_error("-2147483648", ctr);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_count_error('-', ctr);
		n = n * -1;
	}
	if (n >= 0)
	{
		if (n >= 10)
		{
			ft_putnbr_count_error(n / 10, ctr);
			ft_putchar_count_error(n % 10 + '0', ctr);
		}
		else if (n <= 9)
			ft_putchar_count_error(n + '0', ctr);
	}
}

void	ft_putnbr_base_error(size_t n, char *base_str, int is_ptr, int *ctr)
{
	size_t	base;
	int		remainder;

	base = 0;
	while (base_str[base] != '\0')
		base++;
	remainder = n % base;
	if (is_ptr == 1)
		ft_putstr_count_error("0x", ctr);
	if (n >= base)
	{
		ft_putnbr_base_error(n / base, base_str, 0, ctr);
		ft_putchar_count_error(base_str[remainder], ctr);
	}
	else
		ft_putchar_count_error(base_str[remainder], ctr);
}
