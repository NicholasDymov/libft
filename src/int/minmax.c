/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:16:45 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/10 09:23:12 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int64_t	ft_min(int64_t x, int64_t y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int64_t	ft_max(int64_t x, int64_t y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

uint64_t	ft_umin(uint64_t x, uint64_t y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

uint64_t	ft_umax(uint64_t x, uint64_t y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
