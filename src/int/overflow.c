/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:54:11 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 10:55:42 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

int	sizet_mult_overflow(size_t x, size_t y)
{
	if (x > SIZE_MAX / y)
		return (1);
	return (0);
}
