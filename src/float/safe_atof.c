/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:37:05 by ndymov            #+#    #+#             */
/*   Updated: 2026/09/02 12:15:56 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_float.h"
#include "ft_string.h"
#include <float.h>
#include <math.h>
#include <stdint.h>

static inline void	consume_spaces(const char **s_ptr)
{
	while (ft_isspace(**s_ptr))
		*s_ptr += 1;
}

t_error	parse(const char *s, size_t significant_digits, int64_t *significand,
		int *exponent)
{
	int		sign;
	size_t	digits;
	int		frac;

	consume_spaces(&s);
	sign = -((*s == '-') << 1) + 1;
	(void)((*s == '+' || *s == '-') && s++);
	*significand = 0;
	*exponent = 0;
	digits = 0;
	while (digits < significant_digits && ft_isdigit(*s) && ++digits)
		*significand = *significand * 10 + (*(s++) - '0');
	frac = (*s == '.' && s++);
	while (digits < significant_digits && ft_isdigit(*s) && ++digits)
	{
		*significand = *significand * 10 + (*(s++) - '0');
		*exponent -= 1;
	}
	while (!frac && ft_isdigit(*s) && *(s++))
		*exponent += 1;
	consume_spaces(&s);
	if (digits == 0 || (*s != '\0' && !(digits == significant_digits
				&& (ft_isdigit(*s) || *s == '.'))))
		return (ERR_PARSE);
	return (*significand *= sign, OK);
}

t_error	ft_safe_atof(const char *s, float *x)
{
	int64_t	significand;
	int		exponent;
	t_error	err;

	if (s == NULL || x == NULL)
		return (ERR_INVAL);
	err = parse(s, 9, &significand, &exponent);
	if (err)
		return (err);
	*x = (float)significand * ft_powf(10.0f, exponent);
	if (isinf(*x))
		return (ERR_OVERFLOW);
	return (OK);
}

t_error	ft_safe_atod(const char *s, double *x)
{
	int64_t	significand;
	int		exponent;
	t_error	err;

	if (s == NULL || x == NULL)
		return (ERR_INVAL);
	err = parse(s, 17, &significand, &exponent);
	if (err)
		return (err);
	*x = (double)significand * ft_pow(10.0, exponent);
	if (isinf(*x))
		return (ERR_OVERFLOW);
	return (OK);
}
