/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:48:31 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/27 04:55:03 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long	i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
	i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}
