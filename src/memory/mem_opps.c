/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_opps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:34:27 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 10:51:59 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*p;

	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
	{
		p = dest;
		while (n--)
			*(unsigned char *)p++ = *(unsigned char *)src++;
	}
	else
	{
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	}
	return (dest);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0 || s1 == s2)
		return (0);
	while (--n && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	void	*p;

	if (n == 0 || (dst == NULL && src == NULL))
		return (dst);
	p = dst;
	while (n--)
		*(unsigned char *)p++ = *(unsigned char *)src++;
	return (dst);
}

void	*ft_memset(void *s, int c, size_t n)
{
	void	*p;

	p = s;
	while (n--)
		*(unsigned char *)p++ = (unsigned char)c;
	return (s);
}
