/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:22:26 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/29 18:22:01 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_int.h"
#include "ft_string.h"
#include <limits.h>
#include <stdint.h>

int	ft_atoi(const char *s)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		num = num * 10 + (*s++ - '0');
	return (sign * num);
}

uint64_t	ft_atou(const char *s)
{
	uint64_t	num;

	num = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
		return (0);
	while (ft_isdigit(*s))
		num = num * 10 + (*s++ - '0');
	return (num);
}

t_error	ft_safe_atoi(const char *s, int *n)
{
	int		sign;
	int64_t	res;

	res = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		sign = ((*s++ == '+') << 1) - 1;
	if (!ft_isdigit(*s))
		return (ERR_INVAL);
	while (ft_isdigit(*s))
	{
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && ((sign == 1 && (*s
							- '0') > INT_MAX % 10) || (sign == -1 && (*s
							- '0') > INT_MAX % 10 + 1))))
			return (ERR_OVERFLOW);
		res = res * 10 + (*s++ - '0');
	}
	while (ft_isspace(*s))
		s++;
	if (*s != '\0')
		return (ERR_INVAL);
	*n = (int)(res * sign);
	return (OK);
}

t_error	ft_safe_atou(const char *s, uint64_t *n)
{
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	if (!ft_isdigit(*s))
		return (ERR_INVAL);
	*n = 0;
	while (ft_isdigit(*s))
	{
		if ((*n == UINT64_MAX / 10 && (unsigned)(*s - '0') > UINT64_MAX % 10)
			|| *n > UINT64_MAX / 10)
			return (ERR_OVERFLOW);
		*n = *n * 10 + (*s - '0');
		s++;
	}
	while (ft_isspace(*s))
		s++;
	if (*s != '\0')
		return (ERR_INVAL);
	return (OK);
}
