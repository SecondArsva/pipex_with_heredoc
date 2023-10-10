/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:31:34 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/17 20:02:53 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	tmp = NULL;
	next = NULL;
	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next;
	}
	free(tmp);
	*lst = NULL;
}
/*
int	main(void)
{
	t_list	*lst_str;
	t_list	*lst_int;
	int		i;
	int		*num;
	int		total_nodes;

	lst_str = ft_lstnew(ft_strdup("Hey!"));
	i = 0;
	num = ft_calloc(1, sizeof(int));
	if (!num)
		return (0);
	*num = i;
	lst_int = ft_lstnew(num);
	total_nodes = 5;
	while (total_nodes > 0)
	{
		ft_lstadd_front(&lst_str, ft_lstnew(ft_strdup("Hey!")));
		num = ft_calloc(1, sizeof(int));
		*num = i++;
		ft_printf("la: %i\n", i);
		ft_lstadd_front(&lst_int, ft_lstnew(num));
		total_nodes--;
	}
	ft_printf("[LS] lst_str size: %i\n", ft_lstsize(lst_str));
	ft_printf("[LS] lst_int size: %i\n", ft_lstsize(lst_int));
	ft_printf("\n");
	ft_lstprint_str(lst_str, "lst_str");
	ft_printf("\n");
	ft_lstprint_int(lst_int, "lst_int");
	return (0);
}*/
