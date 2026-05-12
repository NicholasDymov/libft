/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:10:33 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/12 19:05:45 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"
#include "ft_hashmap_utils.h"
#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

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

t_entry	*_hashmap_new_entry(const char *key)
{
	t_error	err;
	t_entry	*new_entry;

	new_entry = malloc(sizeof(t_entry));
	if (new_entry == NULL)
		return (NULL);
	if (ft_strlen(key) < HM_SHORTKEY_SIZE)
		err = ft_strdup(&new_entry->key, key);
	else
	{
		(void)ft_strcpy(new_entry->short_key, key);
		new_entry->key = new_entry->short_key;
		err = OK;
	}
	if (err)
		return (free(new_entry), NULL);
	new_entry->value = NULL;
	new_entry->next = NULL;
	return (new_entry);
}

t_entry	*_hashmap_find_entry(t_entry **entry_ptr, const char *key)
{
	t_entry	*entry;

	entry = *entry_ptr;
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
			return (entry);
		entry = entry->next;
	}
	return (NULL);
}

t_entry	*_hashmap_pop_entry(t_entry **entry_ptr, const char *key)
{
	t_entry	*prev;
	t_entry	*curr;
	t_entry	*next;

	prev = NULL;
	curr = *entry_ptr;
	while (curr)
	{
		next = curr->next;
		if (ft_strcmp(curr->key, key) == 0)
			break ;
		prev = curr;
		curr = next;
	}
	if (curr == NULL)
		return (NULL);
	if (prev == NULL)
		*entry_ptr = next;
	else
		prev->next = next;
	return (curr);
}
