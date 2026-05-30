/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:06:05 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/30 17:06:39 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"
#include "ft_hashmap_utils.h"
#include <stdlib.h>

t_error	hashmap_foreach(t_hashmap *hm, t_hashmap_callback callback, void *data)
{
	t_wrapped_callback	wrapped;
	t_error				err;

	if (hm == NULL || callback == NULL)
		return (ERR_INVAL);
	wrapped.callback = callback;
	wrapped.user_data = data;
	err = _hashmap_foreach(hm, _hashmap_callback_wrapper, &wrapped);
	if (err)
		return (err);
	return (OK);
}

void	hashmap_destroy(t_hashmap *hm, void (*destroy)(void *))
{
	if (hm == NULL)
		return ;
	(void)_hashmap_foreach(hm, _hashmap_destroy_entry, &destroy);
	free(hm->buckets);
}
