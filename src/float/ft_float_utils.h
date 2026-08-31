/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 09:59:41 by ndymov            #+#    #+#             */
/*   Updated: 2026/08/24 08:05:05 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_UTILS_H
# define FT_FLOAT_UTILS_H

# include <stdint.h>

# define FL_MINUS 0x01
# define FL_EXP_NEG 0x02

typedef struct s_parse_params
{
	uint8_t		flags;
	uint8_t		precision;
	uint8_t		exp_min;
	uint8_t		exp_max;
}				t_parse_params;

typedef union u_float_bits
{
	float		flt;
	uint32_t	uint;
}				t_float_bits;

typedef union u_double_bits
{
	double		dbl;
	uint64_t	uint;
}				t_double_bits;

void			binarize_exponent(uint64_t *m, int *e, int target_bit);

#endif
