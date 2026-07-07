/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 09:03:06 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/07 11:42:40 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ft_error.h"
# include <stddef.h>

# ifndef MAX_VECTOR_MEMORY
#  define MAX_VECTOR_MEMORY 0x40000000 // 1 GB
# endif

typedef struct s_vector
{
	char	*data;
	size_t	size;
	size_t	capacity;
	size_t	obj_size;
}			t_vector;

t_error		vector_init(t_vector *vec, size_t obj_size, size_t capacity);
t_error		vector_push(t_vector *vec, void *new);
t_error		vector_pop(t_vector *vec);
t_error		vector_foreach(t_vector *vec, t_error (*callback)(void *data,
					void *user_data), void *data);
void		*vector_back(t_vector *vec);
void		*vector_get(t_vector *vec, size_t pos);
char		*vector_to_string(t_vector *vec);
void		vector_clear(t_vector *vec);
void		vector_destroy(t_vector *vec);

#endif
