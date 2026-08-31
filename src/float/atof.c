/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:47:32 by ndymov            #+#    #+#             */
/*   Updated: 2026/08/24 08:04:45 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_float_utils.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdint.h>

float			ft_atof(const char *s);
double			ft_atod(const char *s);

static uint64_t	consume(const char **s, int (*isconsumable)(int), int c)
{
	uint64_t	i;
	const char	*ptr;

	ptr = *s;
	i = 0;
	if (isconsumable != NULL)
	{
		while (isconsumable(ptr[i]))
			i++;
	}
	else
	{
		while (ptr[i] == c)
			i++;
	}
	*s += i;
	return (i);
}

static t_error	parse(const char *s, uint64_t *m, int *e,
		t_parse_params *params)
{
	uint64_t	cnt;

	*e = 1;
	*m = 0;
	params->flags = 0;
	cnt = 0;
	(void)consume(&s, ft_isspace, -1);
	if (*s == '-' || *s == '+')
		params->flags |= FL_MINUS * (*s++ == '-');
	(void)consume(&s, NULL, '0');
	while (ft_isdigit(*s) && cnt++ < params->precision)
		*m = *m * 10 + (*s++ - '0');
	if (*s == '.' && *s++)
		params->flags |= FL_EXP_NEG;
	while (*s == '0' && *s++)
		*e *= 10;
	return (OK);
}

t_error	ft_safe_atof(const char *s, float *x)
{
	t_float_bits	bits;
	t_parse_params	params;
	int				exp;
	uint64_t		significand;

	params.precision = 9;
	if (parse(s, &significand, &exp, &params))
		return (ERR_PARSE);
	binarize_exponent(&significand, &exp, 23);
	exp += 127;
	bits.uint = (uint32_t)significand & 0x7FFFFF;
	bits.uint |= (uint32_t)(exp & 0xFF) << 23;
	bits.uint |= (uint32_t)(params.flags & FL_MINUS) << 31;
	*x = bits.flt;
	return (OK);
}

t_error	ft_safe_atod(const char *s, double *x)
{
	(void)s;
	(void)x;
	return (OK);
}
