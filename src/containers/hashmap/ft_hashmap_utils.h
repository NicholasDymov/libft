/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:07:29 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/11 17:14:14 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHMAP_UTILS
# define FT_HASHMAP_UTILS

# include "ft_hashmap.h"
# include <stdint.h>

typedef t_error	(*t_hashmap_callback_internal)(t_entry *entry, void *data);

t_error			_hashmap_resize(t_hashmap *hm, size_t new_capacity);
t_error			_hashmap_foreach(t_hashmap *hm,
					t_hashmap_callback_internal callback, void *data);
t_error			_hashmap_new_entry(const char *key, t_entry **entry);
t_entry			*_hashmap_find_entry(t_entry *entry, const char *key);

#endif
