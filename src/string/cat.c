/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:57:50 by ndymov            #+#    #+#             */
/*   Updated: 2025/09/04 15:13:46 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*p;

	p = dst;
	while (size && *p)
	{
		p++;
		size--;
	}
	if (size == 0)
		return (p - dst + ft_strlen(src));
	while (--size && *src)
		*p++ = *src++;
	*p = '\0';
	return (p - dst + ft_strlen(src));
}
