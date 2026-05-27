/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:22:26 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 09:42:09 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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

int64_t	ft_atou(const char *s)
{
	int64_t	num;

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
