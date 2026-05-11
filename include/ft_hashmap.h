/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 08:25:39 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/11 17:13:59 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHMAP_H
# define FT_HASHMAP_H

# include "libft.h"
# include <stddef.h>

# ifndef HM_CAP_START
#  define HM_CAP_START 1024
# endif

# ifndef HM_CAP_MAX
#  define HM_CAP_MAX 0x100
# endif

typedef struct s_entry
{
	char			*key;
	void			*value;
	struct s_entry	*next;
}					t_entry;

typedef struct s_hashmap
{
	t_entry			**buckets;
	size_t			size;
	size_t			capacity;
}					t_hashmap;

typedef t_error		(*t_hashmap_callback)(const char *key, void *value,
			void *data);

t_error				hashmap_init(t_hashmap *hm);
t_error				hashmap_put(t_hashmap *hm, const char *key, void *value);
void				*hashmap_get(t_hashmap *hm, const char *key);
t_error				hashmap_foreach(t_hashmap *hm, t_hashmap_callback callback,
						void *data);
void				hashmap_destroy(t_hashmap *hm, void (*destroy)(void *));

#endif
