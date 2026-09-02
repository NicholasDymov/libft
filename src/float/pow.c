/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:23:36 by ndymov            #+#    #+#             */
/*   Updated: 2026/09/02 09:52:35 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>

float	ft_powf(float base, int exponent)
{
	float		res;
	uint64_t	exp;

	if (base == 1.0f)
		return (1.0f);
	else if (base == 0.0f && exponent > 0)
		return (0.0f);
	else if (base == 0.0f && exponent < 0)
		return (NAN);
	if (exponent > 0)
		exp = (uint64_t)exponent;
	else
		exp = (uint64_t)(-(long)exponent);
	res = 1.0f;
	while (exp > 0)
	{
		if (exp & 1)
			res *= base;
		base *= base;
		exp >>= 1;
	}
	if (exponent < 0)
		res = 1.0f / res;
	return (res);
}

double	ft_pow(double base, int exponent)
{
	double		res;
	uint64_t	exp;

	if (base == 1.0)
		return (1.0);
	else if (base == 0.0 && exponent > 0)
		return (0.0);
	else if (base == 0.0 && exponent < 0)
		return (NAN);
	if (exponent > 0)
		exp = (uint64_t)exponent;
	else
		exp = (uint64_t)(-(long)exponent);
	res = 1.0;
	while (exp > 0)
	{
		if (exp & 1)
			res *= base;
		base *= base;
		exp >>= 1;
	}
	if (exponent < 0)
		res = 1.0 / res;
	return (res);
}
