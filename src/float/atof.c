/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:47:32 by ndymov            #+#    #+#             */
/*   Updated: 2026/09/01 12:37:38 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"
#include <float.h>

float	ft_atof(const char *s)
{
	float	x;

	x = 0.0f;
	(void)ft_safe_atof(s, &x);
	return (x);
}

double	ft_atod(const char *s)
{
	double	x;

	x = 0.0;
	(void)ft_safe_atod(s, &x);
	return (x);
}
