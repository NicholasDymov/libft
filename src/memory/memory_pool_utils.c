/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_pool_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:10:48 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/17 16:03:25 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_memory_pool_utils.h"

t_error	__mp_new_block(t_memory_pool *mp)
{
	t_mp_block	*new_block;
	void		*malloc_ptr;
	t_error		err;

	err = ft_aligned_alloc(sizeof(t_mp_block), RAM_PAGE_SIZE,
			(void **)&new_block, &malloc_ptr);
	if (err)
		return (err);
	new_block->malloc_ptr = malloc_ptr;
	__mp_block_intrusive_free_list(new_block, mp);
	new_block->used = 0;
	new_block->prev_block = NULL;
	new_block->next_block = mp->empty_blocks;
	mp->empty_blocks = new_block;
	mp->capacity += mp->obj_per_block;
	return (OK);
}

void	__mp_block_intrusive_free_list(t_mp_block *block, t_memory_pool *mp)
{
	size_t	i;
	void	**pool;

	pool = (void **)&block->pool;
	i = 0;
	while (i + 1 < mp->obj_per_block)
	{
		pool[i * mp->obj_size] = pool + (i + 1) * mp->obj_size;
		i++;
	}
	pool[i * mp->obj_size] = NULL;
	block->free_list = pool;
}
