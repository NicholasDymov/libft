/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:05:03 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/30 17:05:34 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"
#include "ft_hashmap_utils.h"
#include "ft_string.h"
#include <stdlib.h>

t_entry	*_hashmap_new_entry(const char *key)
{
	t_error	err;
	t_entry	*new_entry;

	new_entry = malloc(sizeof(t_entry));
	if (new_entry == NULL)
		return (NULL);
	if (ft_strlen(key) < HM_SHORTKEY_SIZE)
	{
		(void)ft_strcpy(new_entry->short_key, key);
		new_entry->key = new_entry->short_key;
		err = OK;
	}
	else
		err = ft_strdup(&new_entry->key, key);
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
