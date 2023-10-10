/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 03:54:38 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/08 19:12:04 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds a new element to the beginning of a list.
// lst - A pointer to a pointer to a linked list.
// new - the new element to add to the list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*node0;
	t_list	*node1;

	int *a = malloc(sizeof(int));
	*a = 42;	
	int *b = malloc(sizeof(int));
	*b = 56;
	node0 = ft_lstnew(a); // Esto está bien.
	node1 = ft_lstnew(b); // Esto está mal. Así mando la memoria 24.
	ft_printf("node0 (head) pointer: %p | content: %i | next: %p\n",
			node0, *(int *)node0->content, node0->next);
	ft_printf("node1 (head) pointer: %p | content: %i | next: %p\n",
			node1, *(int *)node1->content, node1->next);
	ft_lstadd_front(&node0, node1);
	ft_printf("\n");
	ft_printf("node1 (new head)   pointer: %p | content: %i | next: %p\n",
			node1, *(int *)node1->content, node1->next);
	ft_printf("node0 (lst 'swap') pointer: %p | content: %i | next: %p\n",
			node0, *(int *)node0->content, node0->next);
	ft_printf("node0 (true node0) pointer: %p | content: %i | next: %p\n",
			node1->next, *(int *)node1->next->content, node1->next->next);
	if (node0 == node1)
		ft_printf("wtf\n");
	return (free(node0), 0);
}*/
