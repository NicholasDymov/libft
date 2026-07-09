/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:10:33 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/09 13:11:05 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"
#include "ft_hashmap_utils.h"
#include "ft_memory.h"
#include "ft_utils.h"
#include <stdlib.h>

size_t	_hashmap_index(const char *key, size_t capacity)
{
	return (hash(key) & (capacity - 1));
}

t_error	_hashmap_resize(t_hashmap *hm, size_t new_capacity)
{
	t_hashmap	new_hm;

	if (new_capacity >= HM_CAP_MAX)
		return (ERR_NOMEM);
	new_hm.buckets = ft_calloc(new_capacity, sizeof(t_entry *));
	if (new_hm.buckets == NULL)
		return (ERR_NOMEM);
	new_hm.capacity = new_capacity;
	_hashmap_foreach(hm, _hashmap_move_entry, &new_hm);
	free(hm->buckets);
	hm->buckets = new_hm.buckets;
	hm->capacity = new_hm.capacity;
	hm->max_size = hm->capacity * HM_LOAD_FACTOR_ENUM / HM_LOAD_FACTOR_DENOM;
	return (OK);
}

t_error	_hashmap_foreach(t_hashmap *hm, t_hashmap_callback_internal callback,
		void *data)
{
	size_t	i;
	t_entry	*entry;
	t_entry	*next_entry;
	t_error	err;

	i = 0;
	while (i < hm->capacity)
	{
		entry = hm->buckets[i];
		while (entry)
		{
			next_entry = entry->next;
			err = callback(entry, data);
			if (err)
				return (err);
			entry = next_entry;
		}
		i++;
	}
	return (OK);
}
