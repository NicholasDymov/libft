/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_exponent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 14:44:13 by ndymov            #+#    #+#             */
/*   Updated: 2026/08/24 10:48:23 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

static void	normalize(uint64_t *m, int *e, int target_bit)
{
	static const uint8_t	msb[64] = {0, 11, 1, 12, 16, 29, 2, 13, 22, 17, 41,
			25, 30, 48, 3, 61, 14, 20, 23, 18, 34, 36, 42, 26, 38, 31, 53, 44,
			49, 56, 4, 62, 10, 15, 28, 21, 40, 24, 47, 60, 19, 33, 35, 37, 52,
			43, 55, 9, 27, 39, 46, 59, 32, 51, 54, 8, 45, 58, 50, 7, 57, 6, 5,
			63};
	uint64_t				x;
	int						shift;

	if (*m == 0)
		return ;
	x = *m;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x |= x >> 32;
	shift = msb[(x * 0x03F08A4C6ACB9DBDULL) >> 58] - target_bit;
	if (shift > 0)
		*m = *m >> shift;
	else
		*m = *m << (-shift);
	*e += shift;
}

void	binarize_exponent(uint64_t *m, int *e, int target_bit)
{
	static const uint64_t	powers_positive[9] = {};
	static const uint64_t	powers_negative[9] = {};
	int						i;

	normalize(m, e, 63);
	i = 0;
	while (i < 64)
	{
		if ((1 << i) & 
		i++;
	}
}
