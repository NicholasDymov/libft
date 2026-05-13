/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_callbacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:22:38 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/13 10:20:08 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"
#include "ft_hashmap_utils.h"
#include <stdlib.h>

t_error	_hashmap_callback_wrapper(t_entry *entry, void *data)
{
	t_wrapped_callback	*wrapped;

	wrapped = (t_wrapped_callback *)data;
	return (wrapped->callback(entry->key, entry->value, wrapped->user_data));
}

t_error	_hashmap_move_entry(t_entry *entry, void *data)
{
	t_hashmap	*new_hm;
	size_t		idx;

	new_hm = (t_hashmap *)data;
	idx = _hashmap_index(entry->key, new_hm->capacity);
	entry->next = new_hm->buckets[idx];
	new_hm->buckets[idx] = entry;
	return (OK);
}

t_error	_hashmap_destroy_entry(t_entry *entry, void *data)
{
	void	(**destroy)(void *);

	destroy = (void (**)(void *))data;
	if (destroy != NULL && *destroy != NULL)
		(*destroy)(entry->value);
	if (entry->key != entry->short_key)
		free(entry->key);
	free(entry);
	return (OK);
}
