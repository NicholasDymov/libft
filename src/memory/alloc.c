/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 09:21:39 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 10:59:59 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"
#include "ft_memory.h"
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_size;
	void	*mem;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (sizet_mult_overflow(nmemb, size))
		return (NULL);
	mem_size = nmemb * size;
	mem = malloc(mem_size);
	if (mem == NULL)
		return (NULL);
	return (ft_memset(mem, 0, mem_size));
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
