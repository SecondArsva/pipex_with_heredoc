/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 07:34:19 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/18 01:48:50 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	void	*aux;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		aux = f(lst->content);
		temp = ft_lstnew(aux);
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			del(aux);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst = lst->next;
	}
	return (new_lst);
}
