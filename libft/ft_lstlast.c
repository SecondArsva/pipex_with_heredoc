/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:32:54 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/08 20:58:18 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
//	t_list	*head;
	t_list	*lst;
	int		i;
	int		total_nodes;
	int		*a;

	lst = NULL;
	total_nodes = 5;
	while (i <= total_nodes)
	{
		a = ft_calloc(1, sizeof(int));
		if (!a)
			return (0);
		*a = i;
		ft_lstadd_front(&lst, ft_lstnew(a));
		ft_printf("created node pointer: %p | content: %i | next: %p\n",
				lst, *(int *)lst->content, lst->next);
		i++;
	}
//	ft_printf("pre-segfault if lst isnt initialize and have another t_list\n");
	lst = ft_lstlast(lst);
	ft_printf("\n");
	ft_printf("last node pointer: %p | content: %i | next: %p\n",
			lst, *(int *)lst->content, lst->next);
	return (0);
}*/
