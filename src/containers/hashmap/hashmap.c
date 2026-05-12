/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 08:27:02 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/12 19:03:32 by ndymov           ###   ########.fr       */
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
	t_error	err;
	t_entry	*entry;
	size_t	idx;

	if (hm == NULL || value == NULL || key == NULL)
		return (ERR_INVAL);
	if ((hm->size + 1) * 4 >= hm->capacity * 3)
	{
		err = _hashmap_resize(hm, hm->capacity << 1);
		if (err)
			return (err);
	}
	idx = hash(key) % hm->capacity;
	entry = _hashmap_find_entry(hm->buckets + idx, key);
	if (entry == NULL)
	{
		entry = _hashmap_new_entry(key);
		if (entry == NULL)
			return (ERR_NOMEM);
		entry->next = hm->buckets[idx];
		hm->buckets[idx] = entry;
	}
	entry->value = value;
	hm->size++;
	return (OK);
}

void	*hashmap_get(t_hashmap *hm, const char *key)
{
	t_entry	*entry;
	size_t	idx;

	if (hm == NULL || key == NULL)
		return (NULL);
	idx = hash(key) % hm->capacity;
	entry = _hashmap_find_entry(hm->buckets + idx, key);
	if (entry == NULL)
		return (NULL);
	return (entry->value);
}

void	*hashmap_pop(t_hashmap *hm, const char *key)
{
	size_t	idx;
	t_entry	*entry;
	void	*value;

	if (hm == NULL || key == NULL)
		return (NULL);
	idx = hash(key) % hm->capacity;
	entry = _hashmap_pop_entry(hm->buckets + idx, key);
	if (entry == NULL)
		return (NULL);
	value = entry->value;
	(void)_hashmap_destroy_entry(entry, NULL);
	return (value);
}

t_error	hashmap_foreach(t_hashmap *hm, t_hashmap_callback callback, void *data)
{
	t_wrapped_callback	wrapped;
	t_error				err;

	if (hm == NULL || callback == NULL)
		return (ERR_INVAL);
	_wrapped_callback_init(&wrapped, callback, data, NULL);
	err = _hashmap_foreach(hm, _hashmap_callback_wrapper, &wrapped);
	if (err)
		return (err);
	return (OK);
}

void	hashmap_destroy(t_hashmap *hm, void (*destroy)(void *))
{
	t_wrapped_callback	wrapped;

	if (hm == NULL)
		return ;
	_wrapped_callback_init(&wrapped, NULL, NULL, destroy);
	(void)_hashmap_foreach(hm, _hashmap_destroy_entry, &wrapped);
	free(hm->buckets);
}
