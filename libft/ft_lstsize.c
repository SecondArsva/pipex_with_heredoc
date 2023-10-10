/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:46:42 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/17 07:11:25 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function use the variable used to the next
// node of each node to return the total size of a list.
int	ft_lstsize(t_list *list)
{
	int	total_nodes;

	total_nodes = 0;
	while (list)
	{
		total_nodes++;
		list = list->next;
	}
	return (total_nodes);
}
/*
int	main(void)
{
	t_list	*lst;
	int		i;
	int		total_nodes;

	lst = ft_lstnew(NULL);
	i = 0;
	total_nodes = 42;
	while (i++ < total_nodes)
		ft_lstadd_front(&lst, ft_lstnew(NULL));
	ft_printf("List size: %i\n", ft_lstsize(lst));
	return (0);
}*/
