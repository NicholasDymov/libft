/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:19:50 by ndymov            #+#    #+#             */
/*   Updated: 2025/09/10 17:27:08 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

#define INT_MIN_STR "-2147483648"

size_t	get_size(int n);

char	*ft_itoa(int n)
{
	char	*arr;
	size_t	size;

	size = get_size(n);
	arr = malloc(size);
	if (arr == NULL)
		return (NULL);
	if (n == INT_MIN)
		return (ft_strlcpy(arr, INT_MIN_STR, size), arr);
	if (n == 0)
		return (ft_strlcpy(arr, "0", size), arr);
	if (n < 0)
	{
		*arr = '-';
		n = -n;
	}
	arr[--size] = '\0';
	while (n > 0)
	{
		arr[--size] = '0' + n % 10;
		n /= 10;
	}
	return (arr);
}

size_t	get_size(int n)
{
	size_t	size;

	if (n == INT_MIN)
		return (ft_strlen(INT_MIN_STR) + 1);
	if (n == 0)
		return (2);
	size = 0;
	if (n < 0)
	{
		size += 1;
		n = -n;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}
