/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:57:50 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 11:32:45 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcpy(char *restrict dst, const char *restrict src)
{
	char	*dst_ptr;

	dst_ptr = dst;
	while (*src)
		*dst_ptr++ = *src++;
	*dst_ptr = '\0';
	return (dst);
}

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	char	*dst_ptr;

	dst_ptr = dst;
	while (n && *src)
	{
		*dst_ptr++ = *src++;
		n--;
	}
	while (n--)
		*dst_ptr++ = '\0';
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*p;

	if (size == 0)
		return (ft_strlen(src));
	p = dst;
	while (--size && *src)
		*p++ = *src++;
	*p = '\0';
	return (p - dst + ft_strlen(src));
}
