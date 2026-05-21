/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:44:55 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/21 10:50:50 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_lstadd_back(t_list **lst, t_list *new_elem)
{
	t_list	*last;

	if (lst == NULL || new_elem == NULL)
		return ;
	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = new_elem;
	else
		last->next = new_elem;
}

void	ft_lstadd_front(t_list **lst, t_list *new_elem)
{
	if (new_elem == NULL)
		return ;
	new_elem->next = *lst;
	*lst = new_elem;
}
