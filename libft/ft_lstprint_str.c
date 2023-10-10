/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:08:30 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/12 06:29:32 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_str(t_list *lst, char *name)
{
	if (!lst || !name)
		return ;
	while (lst->next)
	{
		ft_printf("%s pointer: %p | content: %s | next: %p\n",
			name, lst, (char *)lst->content, lst->next);
		lst = lst->next;
	}
	ft_printf("%s pointer: %p | content: %s | next: %p\n",
		name, lst, (char *)lst->content, lst->next);
}
