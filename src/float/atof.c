/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:47:32 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/10 14:54:02 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

float	ft_atof(const char *s);
double	ft_atod(const char *s);

t_error	ft_safe_atof(const char *s, float *x);
t_error	ft_safe_atod(const char *s, double *x);
