/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 10:39:32 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/10 14:53:05 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include "ft_error.h"
# include <stddef.h>

float	ft_minf(float x, float y);
float	ft_maxf(float x, float y);
double	ft_mind(double x, double y);
double	ft_maxd(double x, double y);

float	ft_atof(const char *s);
double	ft_atod(const char *s);

t_error	ft_safe_atof(const char *s, float *x);
t_error	ft_safe_atod(const char *s, double *x);

char	*ft_ftoa(float x);
char	*ft_dtoa(double x);

size_t	ft_ftobuff(float x, char *buff, size_t n);
size_t	ft_dtobuff(double x, char *buff, size_t n);

#endif
