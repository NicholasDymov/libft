/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 08:58:33 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/26 12:05:29 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"
#include "ft_memory_pool_utils.h"
#include <stdlib.h>

t_error	memory_pool_init(t_memory_pool *mp, size_t capacity, size_t obj_size)
{
	t_error	err;

	if (mp == NULL || capacity == 0 || obj_size == 0
		|| capacity >= MP_MAX_CAPACITY)
		return (ERR_INVAL);
	if (obj_size <= CACHE_LINE_SIZE)
		mp->obj_size = po2_up(obj_size);
	else
		mp->obj_size = multiple_up(obj_size, CACHE_LINE_SIZE);
	if (mp->obj_size == 0 || mp->obj_size > MP_BLOCK_SIZE
		|| mp->obj_size < sizeof(void *))
		return (ERR_INVAL);
	mp->obj_per_block = MP_BLOCK_SIZE / mp->obj_size;
	mp->empty_blocks = NULL;
	mp->partial_blocks = NULL;
	mp->full_blocks = NULL;
	mp->used = 0;
	mp->capacity = 0;
	while (mp->capacity < capacity)
	{
		err = _mp_new_block(mp);
		if (err)
			return (err);
	}
	return (OK);
}

void	memory_pool_destroy(t_memory_pool *mp)
{
	_mp_block_destroy(mp->empty_blocks);
	_mp_block_destroy(mp->partial_blocks);
	_mp_block_destroy(mp->full_blocks);
	mp->empty_blocks = NULL;
	mp->partial_blocks = NULL;
	mp->full_blocks = NULL;
	mp->used = 0;
	mp->capacity = 0;
}

void	*memory_pool_get(t_memory_pool *mp)
{
	if (mp->partial_blocks != NULL)
		return (_mp_block_get(mp->partial_blocks, mp));
	if (mp->empty_blocks != NULL)
		return (_mp_block_get(mp->empty_blocks, mp));
	if (_mp_new_block(mp))
		return (NULL);
	return (_mp_block_get(mp->empty_blocks, mp));
}

void	memory_pool_return(t_memory_pool *mp, void *obj)
{
	t_mp_block	*block;

	block = _mp_block_address(obj);
	_mp_block_return(block, mp, obj);
}
