/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 08:24:26 by ndymov            #+#    #+#             */
/*   Updated: 2026/09/05 14:18:48 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stddef.h>

int	ft_str_startswith(const char *str, const char *prefix)
{
	if (str == NULL || prefix == NULL)
		return (0);
	while (*prefix)
	{
		if (*str++ != *prefix++)
			return (0);
	}
	return (1);
}

int	ft_str_endswith(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suf_len;

	if (str == NULL || suffix == NULL)
		return (0);
	suf_len = ft_strlen(suffix);
	if (suf_len == 0)
		return (1);
	str_len = ft_strlen(str);
	if (str_len < suf_len)
		return (0);
	if (str[str_len - 1] != suffix[suf_len - 1] || str[str_len
		- suf_len] != suffix[0])
		return (0);
	if (suf_len <= 2)
		return (1);
	return (ft_memcmp(str + (str_len - suf_len), suffix, suf_len - 1) == 0);
}
