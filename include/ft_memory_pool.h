/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_pool.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:40:18 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/21 11:01:08 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_POOL_H
# define FT_MEMORY_POOL_H

# include "libft.h"
# include <stddef.h>
# include <stdint.h>

# ifndef CACHE_LINE_SIZE
#  define CACHE_LINE_SIZE 64
# endif

# ifndef MP_BLOCK_ALIGNMENT
#  define MP_BLOCK_ALIGNMENT 4096
# endif

# ifndef MP_BLOCK_SIZE
#  define MP_BLOCK_SIZE 4032 // page size - cache line size
# endif

# ifndef MP_MAX_CAPACITY
#  define MP_MAX_CAPACITY 0x1000
# endif

typedef struct s_mp_block
{
	uint8_t				pool[MP_BLOCK_SIZE];
	struct s_mp_block	*next;
	struct s_mp_block	*prev;
	void				**free_list;
	void				*malloc_ptr;
	size_t				used;
}						t_mp_block;

typedef struct s_memory_pool
{
	size_t				used;
	size_t				capacity;
	size_t				obj_size;
	size_t				obj_per_block;
	t_mp_block			*empty_blocks;
	t_mp_block			*partial_blocks;
	t_mp_block			*full_blocks;
}						t_memory_pool;

t_error					memory_pool_init(t_memory_pool *mp, size_t capacity,
							size_t obj_size);
void					*memory_pool_get(t_memory_pool *mp);
void					memory_pool_return(t_memory_pool *mp, void *obj);

#endif
