/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_pool.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:40:18 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/14 22:12:23 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_POOL_H
# define FT_STRING_POOL_H

# include "libft.h"
# include <stddef.h>

# define SP_BLOCK_SIZE 4032 // page size - cache line size

typedef struct s_sp_block
{
	char				pool[SP_BLOCK_SIZE];
	size_t				pos;
	struct s_sp_block	*next;
}						t_sp_block;

typedef struct s_string_pool
{
	size_t				used;
	size_t				capacity;
	t_sp_block			*current;
	t_sp_block			*blocks;
}						t_string_pool;

t_error					string_pool_init(t_string_pool *sp, size_t capacity);

#endif
