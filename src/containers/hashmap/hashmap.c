/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 08:27:02 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/11 16:36:34 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_hashmap.h"
#include "ft_hashmap_utils.h"
#include <stdlib.h>

t_error	hashmap_init(t_hashmap *hm)
{
	t_error	err;

	if (hm == NULL)
		return (ERR_INVAL);
	hm->size = 0;
	err = _hashmap_resize(hm, HM_CAP_START);
	if (err)
		return (err);
	hm->capacity = HM_CAP_START;
	return (OK);
}

t_error	hashmap_put(t_hashmap *hm, const char *key, void *value)
{
	t_error		err;
	t_entry		*entry;
	uint64_t	key_hash;

	if (hm == NULL || key == NULL || value == NULL)
		return (ERR_INVAL);
	if ((hm->size + 1) * 4 >= hm->capacity * 3)
	{
		err = _hashmap_resize(hm, hm->capacity << 1);
		if (err)
			return (err);
	}
	key_hash = hash(key);
	entry = _hashmap_find_entry(hm->buckets[key_hash % hm->capacity], key);
	if (entry == NULL)
	{
		err = _hashmap_new_entry(key, &entry);
		if (err)
			return (err);
		entry->next = hm->buckets[key_hash];
		hm->buckets[key_hash] = entry;
	}
	entry->value = value;
	hm->size++;
	return (OK);
}

void	*hashmap_get(t_hashmap *hm, const char *key)
{
	t_entry		*entry;
	uint64_t	key_hash;

	if (hm == NULL || key == NULL)
		return (NULL);
	key_hash = hash(key);
	entry = _hashmap_find_entry(hm->buckets[key_hash], key);
	if (entry == NULL)
		return (NULL);
	return (entry->value);
}

void	*hashmap_pop(t_hashmap *hm, const char *key)
{
	t_entry		*entry;
	uint64_t	key_hash;

	if (hm == NULL || key == NULL)
		return (NULL);
	key_hash = hash(key);
	entry = _hashmap_find_entry(hm->buckets[key_hash], key);
	if (entry == NULL)
		return (NULL);
	return (entry->value);
}

t_error	hashmap_foreach(t_hashmap *hm, t_hashmap_callback callback, void *data)
{
	size_t	i;
	t_entry	*entry;
	t_error	err;

	if (hm == NULL || callback == NULL)
		return (ERR_INVAL);
	i = 0;
	while (i < hm->capacity)
	{
		entry = hm->buckets[i];
		while (entry)
		{
			err = callback(entry->key, entry->value, data);
			if (err)
				return (err);
			entry = entry->next;
		}
		i++;
	}
	return (OK);
}

void	hashmap_destroy(t_hashmap *hm, void (*destroy)(void *))
{
	size_t	i;
	t_entry	*entry;
	t_entry	*next_entry;

	if (hm == NULL)
		return ;
	i = 0;
	while (i < hm->capacity)
	{
		entry = hm->buckets[i];
		while (entry)
		{
			if (destroy != NULL)
				destroy(entry->value);
			free(entry->key);
			next_entry = entry->next;
			free(entry);
			entry = next_entry;
		}
		i++;
	}
	free(hm->buckets);
}
