/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_pool_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:10:03 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/17 15:42:48 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_POOL_UTILS_H
# define FT_MEMORY_POOL_UTILS_H

# include "ft_memory.h"

t_error	__mp_new_block(t_memory_pool *mp);
void	__mp_block_intrusive_free_list(t_mp_block *block, t_memory_pool *mp);

#endif
