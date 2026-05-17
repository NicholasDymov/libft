/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_of_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 10:40:47 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/17 14:59:17 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"
#include <stdint.h>

/*
** Returns the smallest power of 2 >= x.
** Returns 0 on error as a result of overflow.
*/
uint64_t	po2_up(uint64_t x)
{
	if (x <= 1)
		return (1);
	x--;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x |= x >> 32;
	x++;
	return (x);
}

/*
** Returns the largest power of <= x.
** Returns 0 for x == 0.
*/
uint64_t	po2_down(uint64_t x)
{
	if (x == 0)
		return (0);
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x |= x >> 32;
	return (x - (x >> 1));
}
