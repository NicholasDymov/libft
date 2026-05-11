/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:10:33 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/11 17:13:53 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_hashmap.h"
#include "ft_hashmap_utils.h"
#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

static t_error	move_entries(t_entry *entry, void *data)
{
	t_hashmap	*hm;
	uint64_t	key_hash;

	hm = (t_entry **)data;
	key_hash = hash(entry->key);
	entry->next = new_buckets[key_hash % 2];
}

t_error	_hashmap_resize(t_hashmap *hm, size_t new_capacity)
{
	t_entry	**new_buckets;

	new_buckets = ft_calloc(new_capacity, sizeof(t_entry *));
	if (new_buckets == NULL)
		return (ERR_NOMEM);
	hm->capacity = new_capacity;
	_hashmap_foreach(hm, move_entries, hm);
	free(hm->buckets);
	hm->buckets = new_buckets;
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
	while (i < hm->size)
	{
		entry = hm->buckets[i];
		while (entry)
		{
			err = callback(entry, data);
			if (err)
				return (err);
			entry = entry->next;
		}
		i++;
	}
	return (OK);
}

t_error	_hashmap_new_entry(const char *key, t_entry **entry)
{
	t_error	err;
	t_entry	*new_entry;

	new_entry = malloc(sizeof(t_entry));
	if (*entry == NULL)
		return (ERR_NOMEM);
	err = ft_strdup(&new_entry->key, key);
	if (err)
		return (free(new_entry), err);
	*entry = new_entry;
	return (OK);
}

t_entry	*_hashmap_find_entry(t_entry *entry, const char *key)
{
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
			return (entry);
		entry = entry->next;
	}
	return (NULL);
}
