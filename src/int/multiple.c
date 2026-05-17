/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:04:32 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/17 14:56:39 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"
#include <stdint.h>

/*
** Rounds x down to the nearest multiple of div.
** div must be > 0
** Safety checks are not performed as the function is intended for internal use
*/
uint64_t	multiple_down(uint64_t x, uint64_t div)
{
	return (x - x % div);
}

/*
** Rounds x up to the nearest multiple of div.
** div must be > 0
** Safety checks are not performed as the function is intended for internal use
*/
uint64_t	multiple_up(uint64_t x, uint64_t div)
{
	uint64_t	rem;

	rem = x % div;
	if (rem == 0)
		return (x);
	return (x + div - rem);
}

/*
** Rounds x down to the nearest multiple of div (where div is a power of two).
** div must be > 0 and a power of two
** Safety checks are not performed as the function is intended for internal use
*/
uint64_t	multiple_po2_down(uint64_t x, uint64_t div)
{
	return (x & ~(div - 1));
}

/*
** Rounds x up to the nearest multiple of div (where div is a power of two).
** div must be > 0 and a power of two
** Safety checks are not performed as the function is intended for internal use
*/
uint64_t	multiple_po2_up(uint64_t x, uint64_t div)
{
	if ((x & (div - 1)) == 0)
		return (x);
	return ((x & ~(div - 1)) + div);
}
