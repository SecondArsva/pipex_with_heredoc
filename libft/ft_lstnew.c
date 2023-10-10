/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 03:02:33 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/07 04:49:24 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It creates a new list node with the given
// content and returns a pointer to it.
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = ft_calloc(1, sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
void	ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	atexit(ft_leaks);
	t_list *node_int;
	t_list *node_str;
	int *a;
	char *str; 

	a = ft_calloc(1, sizeof(int));
	if (!a)
		return (0);
	*a = 88;
	str = ft_strdup("El miedo mata la mente.");
	if (!str)
		return (0);
	node_int = NULL;
	node_str = NULL;
	ft_printf("node_int pointer pre-ft =	%p\n", node_int);
	ft_printf("node_char pointer pre-ft =	%p\n", node_str);
	node_int = ft_lstnew(a);
	node_str = ft_lstnew(str);
	ft_printf("node_int post-ft = %p\n", node_int);
	ft_printf("node_int content = %i\n", *(int *)node_int->content);
	ft_printf("node_str post-ft = %p\n", node_str);
	ft_printf("node_str content = %s\n", (char *)node_str->content);
	return (free(node_int), free(node_str), free(a), free(str), 0);
}*/
