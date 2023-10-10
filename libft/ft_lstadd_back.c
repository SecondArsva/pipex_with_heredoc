/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:14:31 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/17 19:55:50 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	last_node = NULL;
	if (!new)
		return ;
	last_node = ft_lstlast(*lst);
	if (last_node)
		last_node->next = new;
	else
		*lst = new;
}
/*
void ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	t_list	*head;
	t_list	*lst;
	int		total_nodes;
	int		i;
	int		*a;

	atexit(ft_leaks);
	head = ft_lstnew(NULL);
	ft_printf("[H] head pointer: %p | content: %i | next: %p\n",
			head, head->content, head->next);
	lst = NULL;
	total_nodes = 5;
	i = 0;
	while (i <= total_nodes)
	{
		ft_printf("[i] iter val: %i\n", i);
		a = ft_calloc(1, sizeof(int));
		if (!a)
			return (0);
		*a = i;
		lst = ft_lstnew(a);
		ft_lstadd_back(&head, lst);
		ft_printf("[LOOP] node created pointer: %p | content: %i | next: %p\n",
				lst, *(int *)lst->content, lst->next);
		free(a);
		i++;
	}
	ft_printf("[EXIT] Sale del bucle.\n");
	lst = ft_lstlast(lst);
	ft_printf("[Last] last created pointer: %p | content: %i | next: %p\n",
			lst, *(int *)lst->content, lst->next);
	ft_printf("[NW] ->Next Viewer\n");;
	ft_printf("[NW] node pointer: %p | next: %p\n",
			head, head->next);
	while (head->next)
	{
		head = head->next;
		ft_printf("[NW] node pointer: %p | next: %p\n",
				head, head->next);
	}
	return (free(lst), 0);
}*/
