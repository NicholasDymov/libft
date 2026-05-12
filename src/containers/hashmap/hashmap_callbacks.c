/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_callbacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:22:38 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/12 19:05:41 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_hashmap.h"
#include "ft_hashmap_utils.h"
#include <stdlib.h>

void	_wrapped_callback_init(t_wrapped_callback *wrapped,
		t_hashmap_callback callback, void *data, void (*destroy)(void *))
{
	wrapped->callback = callback;
	wrapped->user_data = data;
	wrapped->destroy = destroy;
}

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
	idx = hash(entry->key) % new_hm->capacity;
	entry->next = new_hm->buckets[idx];
	new_hm->buckets[idx] = entry;
	return (OK);
}

t_error	_hashmap_destroy_entry(t_entry *entry, void *data)
{
	t_wrapped_callback	*wrapped;

	wrapped = (t_wrapped_callback *)data;
	if (wrapped->destroy != NULL)
		wrapped->destroy(entry->value);
	if (entry->key != entry->short_key)
		free(entry->key);
	free(entry);
	return (OK);
}
