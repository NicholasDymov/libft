/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:07:29 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/13 09:28:00 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHMAP_UTILS_H
# define FT_HASHMAP_UTILS_H

# include "ft_hashmap.h"
# include <stdint.h>

typedef t_error			(*t_hashmap_callback_internal)(t_entry *entry,
				void *data);

typedef struct s_wrapped_callback
{
	t_hashmap_callback	callback;
	void				*user_data;
}						t_wrapped_callback;

t_error					_hashmap_callback_wrapper(t_entry *entry, void *data);
t_error					_hashmap_move_entry(t_entry *entry, void *data);
t_error					_hashmap_resize(t_hashmap *hm, size_t new_capacity);
t_error					_hashmap_foreach(t_hashmap *hm,
							t_hashmap_callback_internal callback, void *data);
size_t					_hashmap_index(const char *key, size_t capacity);
t_entry					*_hashmap_new_entry(const char *key);
t_entry					*_hashmap_find_entry(t_entry **entry_ptr,
							const char *key);
t_entry					*_hashmap_pop_entry(t_entry **entry_ptr,
							const char *key);
t_error					_hashmap_destroy_entry(t_entry *entry, void *data);

#endif
