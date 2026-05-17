/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 09:03:06 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/15 22:29:57 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"
# include <stddef.h>

# ifndef MAX_VECTOR_CAPACITY
#  define MAX_VECTOR_CAPACITY 0x1000
# endif

typedef struct s_vector
{
	void	**data;
	size_t	size;
	size_t	capacity;
}			t_vector;

t_error		vector_init(t_vector *vec, size_t capacity);
t_error		vector_push(t_vector *vec, void *new);
void		*vector_pop(t_vector *vec);
void		vector_destroy(t_vector *vec, void (*destroy)(void *));

#endif
