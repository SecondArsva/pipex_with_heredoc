/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:45:07 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/17 19:51:12 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*tmp;								// a
	int		total_nodes;
	int		i;

	lst = NULL;
	total_nodes = 5;
	i = -1;
	while (++i <= total_nodes)
		ft_lstadd_front(&lst, ft_lstnew(NULL));
	ft_printf("[LS] List size: %i\n", ft_lstsize(lst));
	if (lst && lst->next && lst->next->next) 
	{
		tmp = lst->next->next;					// a
		lst->next->next = tmp->next;			// a
		ft_lstdelone(tmp, free);				// a
//		ft_lstdelone(lst->next->next, free);	// b
	}
	ft_printf("[LS] List size: %i\n", ft_lstsize(lst));
	return (0);
}*/
