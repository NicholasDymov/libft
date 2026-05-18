/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_pool_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:10:03 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/18 16:56:29 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_POOL_UTILS_H
# define FT_MEMORY_POOL_UTILS_H

# include "ft_memory.h"

t_error	_mp_new_block(t_memory_pool *mp);
void	_mp_block_intrusive_free_list(t_mp_block *block, t_memory_pool *mp);
void	*_mp_block_get(t_mp_block *block, t_memory_pool *mp);
void	_mp_block_return(t_mp_block *block, t_memory_pool *mp, void *obj);
void	_mp_block_move(t_mp_block *block, t_mp_block **list);
void	*_mp_block_address(void *obj);

#endif
