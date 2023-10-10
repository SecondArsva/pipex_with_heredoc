/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 03:46:24 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/14 07:33:57 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int	main(void)
{
	t_list	*lst;
	int		total_nodes;

	lst = NULL;
	total_nodes = 5;
	while (total_nodes > 0)
	{
		ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Hey!")));
		ft_printf("Node content: %s\n", (char *)lst->content);
		total_nodes--;
	}
	ft_lstiter(lst, (void *)ft_isprint);
	ft_printf("Node content: %i\n", (int *)lst->content);
	return (0);
}*/
