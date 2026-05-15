/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_pool_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:26:59 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/14 22:12:34 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_POOL_UTILS_H
# define FT_STRING_POOL_UTILS_H

# include "ft_string_pool.h"
# include "libft.h"

t_error	_sp_grow(t_string_pool *sp, size_t new_capacity);

#endif
