/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:41:51 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/21 11:00:31 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include "ft_error.h"
# include <stddef.h>

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);
t_error	ft_aligned_alloc(size_t n, size_t alignment, void **aligned_ptr,
			void **raw_ptr);

#endif
