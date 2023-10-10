/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:40:24 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/27 13:32:08 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_int(t_list *lst, char *name)
{
	if (!lst || !name)
		return ;
	while (lst->next)
	{
		ft_printf("%s pointer: %p | content: %i | next: %p\n",
			name, lst, *(int *)lst->content, lst->next);
		lst = lst->next;
	}
	ft_printf("%s pointer: %p | content: %i | next: %p\n",
		name, lst, *(int *)lst->content, lst->next);
}
