/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 03:54:27 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/18 04:22:44 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(size_t n)
{
	t_list	*new_lst;

	new_lst = NULL;
	while (n > 0)
	{
		ft_lstadd_front(&new_lst, ft_lstnew(NULL));
		n--;
	}
	return (new_lst);
}
/*
int	main(void)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = ft_lstcreate(4);
	lst_b = ft_lstcreate(9);
	ft_printf("[LS] a: %i\n", ft_lstsize(lst_a));
	ft_lstprint_str(lst_a, "lst_a");
	ft_printf("[LS] b: %i\n", ft_lstsize(lst_b));
	ft_lstprint_str(lst_b, "lst_b");
	return (0);
}*/
