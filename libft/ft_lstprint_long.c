/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:58:37 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/27 20:19:12 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_long(t_list *lst, char *name)
{
	if (!lst || !name)
		return ;
	while (lst->next)
	{
		ft_printf("%s pointer: %p | content: %l | next: %p\n",
			name, lst, *(long *)lst->content, lst->next);
		lst = lst->next;
	}
	ft_printf("%s pointer: %p | content: %l | next: %p\n",
		name, lst, *(long *)lst->content, lst->next);
}
