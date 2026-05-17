/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 09:21:39 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/17 09:39:48 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
}

t_error	ft_aligned_alloc(size_t n, size_t alignment, void **aligned_ptr,
		void **raw_ptr)
{
	*raw_ptr = malloc(n + alignment);
	if (*raw_ptr == NULL)
		return (ERR_NOMEM);
	*aligned_ptr = (void *)((uintptr_t)(*raw_ptr + alignment
				- 1) & ~(uintptr_t)(alignment - 1));
	return (OK);
}
