/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:47:09 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/14 22:12:18 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_pool.h"
#include "ft_string_pool_utils.h"

t_error	string_pool_init(t_string_pool *sp, size_t capacity)
{
	t_error	err;

	if (sp == NULL)
		return (ERR_INVAL);
	sp->used = 0;
	err = _sp_grow(sp, capacity);
	if (err)
		return (err);
}
