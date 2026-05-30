/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_pool_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:10:48 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/30 17:15:06 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_memory_pool_utils.h"
#include <stdlib.h>

t_error	_mp_new_block(t_memory_pool *mp)
{
	t_mp_block	*new_block;
	void		*malloc_ptr;
	t_error		err;

	err = ft_aligned_alloc(sizeof(t_mp_block), MP_BLOCK_ALIGNMENT,
			(void **)&new_block, &malloc_ptr);
	if (err)
		return (err);
	new_block->malloc_ptr = malloc_ptr;
	_mp_block_intrusive_free_list(new_block, mp);
	new_block->used = 0;
	new_block->prev = NULL;
	new_block->next = mp->empty_blocks;
	mp->empty_blocks = new_block;
	mp->capacity += mp->obj_per_block;
	return (OK);
}

void	*_mp_block_get(t_mp_block *block, t_memory_pool *mp)
{
	void	**obj;

	if (block->used == mp->obj_per_block)
		return (NULL);
	obj = block->free_list;
	block->free_list = *obj;
	if (block->used + 1 == mp->obj_per_block)
		_mp_block_move(block, &mp->partial_blocks, &mp->full_blocks);
	else if (block->used == 0)
		_mp_block_move(block, &mp->empty_blocks, &mp->partial_blocks);
	block->used++;
	return (obj);
}

void	_mp_block_return(t_mp_block *block, t_memory_pool *mp, void *obj)
{
	*(void **)obj = block->free_list;
	block->free_list = (void **)obj;
	if (block->used == 1)
		_mp_block_move(block, &mp->partial_blocks, &mp->empty_blocks);
	else if (block->used == mp->obj_per_block)
		_mp_block_move(block, &mp->full_blocks, &mp->partial_blocks);
	block->used--;
}

void	_mp_block_destroy(t_mp_block *block)
{
	t_mp_block	*next_block;

	while (block != NULL)
	{
		next_block = block->next;
		free(block->malloc_ptr);
		block = next_block;
	}
}
