/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_pool_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:14:38 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/30 17:23:52 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory_pool.h"

void	_mp_block_intrusive_free_list(t_mp_block *block, t_memory_pool *mp)
{
	size_t		i;
	uintptr_t	ptr;

	ptr = (uintptr_t) & block->pool;
	i = 0;
	while (i + 1 < mp->obj_per_block)
	{
		*(void **)ptr = (void *)(ptr + mp->obj_size);
		ptr += mp->obj_size;
		i++;
	}
	*(void **)ptr = NULL;
	block->free_list = (void **)&block->pool;
}

void	_mp_block_move(t_mp_block *block, t_mp_block **src_list,
		t_mp_block **dst_list)
{
	if (block->prev != NULL)
		block->prev->next = block->next;
	else
		*src_list = block->next;
	if (block->next != NULL)
		block->next->prev = block->prev;
	if (*dst_list != NULL)
		(*dst_list)->prev = block;
	block->next = *dst_list;
	block->prev = NULL;
	*dst_list = block;
}

void	*_mp_block_address(void *obj)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)obj;
	return ((void *)(ptr & ~(MP_BLOCK_ALIGNMENT - 1)));
}
