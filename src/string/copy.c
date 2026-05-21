/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:57:50 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/21 10:27:01 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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
