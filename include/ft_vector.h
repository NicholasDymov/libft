/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 09:03:06 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/09 09:04:53 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

# define MAX_VECTOR_CAPACITY 0x1000

typedef struct s_vector
{
	void	**data;
	void	(*destroy)(void *);
	size_t	size;
	size_t	capacity;
}			t_vector;
#endif
