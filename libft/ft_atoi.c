/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:51:01 by davidga2          #+#    #+#             */
/*   Updated: 2023/03/22 22:47:27 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

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
/*
int	main(void)
{
	char	stringZER0[] = "-000";
	char	string0[] = "000";
	char	string1[] = "111";
	char	string2[] = "-222";
	char	string3[] = " -333";
	char	string4[] = "     +444";
	char	string5[] = "  -+-+-555";
	char	string6[] = "      -66a6";

	printf("StringZER0: %d | ft_atoi\n", ft_atoi(stringZER0));
	printf("StringZER0: %d | atoi\n", atoi(stringZER0));
	printf("String0: %d | ft_atoi\n", ft_atoi(string0));
	printf("String0: %d | atoi\n", atoi(string0));
	printf("String1: %d | ft_atoi\n", ft_atoi(string1));
	printf("String1: %d | atoi\n", atoi(string1));
	printf("String2: %d | ft_atoi\n", ft_atoi(string2));
	printf("String2: %d | atoi\n", atoi(string2));
	printf("String3: %d | ft_atoi\n", ft_atoi(string3));
	printf("String3: %d | atoi\n", atoi(string3));
	printf("String4: %d | ft_atoi\n", ft_atoi(string4));
	printf("String4: %d | atoi\n", atoi(string4));
	printf("String5: %d | ft_atoi\n", ft_atoi(string5));
	printf("String5: %d | atoi\n", atoi(string5));
	printf("String6: %d | ft_atoi\n", ft_atoi(string6));
	printf("String6: %d | atoi\n", atoi(string6));
}*/
