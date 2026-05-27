/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itobuff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 09:50:50 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 10:47:44 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define INT_MIN_STR "-2147483648"

static size_t	ft_utoa_rec(uint64_t n, char *buff, size_t offset)
{
	size_t	res;

	if (n == 0)
		return (offset);
	res = ft_utoa_rec(n / 10, buff, offset + 1);
	buff[res - offset - 1] = '0' + n % 10;
	return (res);
}

size_t	ft_utobuff(uint64_t n, char *buff)
{
	size_t	size;

	if (n == 0)
	{
		buff[0] = '0';
		buff[1] = '\0';
		return (1);
	}
	size = ft_utoa_rec(n, buff, 0);
	buff[size] = '\0';
	return (size);
}

size_t	ft_itobuff(int n, char *buff)
{
	size_t	size;

	if (n == INT_MIN)
		return (ft_strlcpy(buff, INT_MIN_STR, ft_strlen(INT_MIN_STR) + 1));
	size = 0;
	if (n < 0)
	{
		*buff++ = '-';
		size++;
		n = -n;
	}
	size += ft_utobuff(n, buff);
	return (size);
}
