/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:04:30 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/11 11:01:59 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

uint64_t	hash(const char *str)
{
	uint64_t			hash;
	int					c;
	const unsigned char	*ptr;

	ptr = (unsigned char *)str;
	hash = 5381;
	c = *ptr;
	while (c)
	{
		hash = (hash << 5) + hash + c;
		c = *(++ptr);
	}
	return (hash);
}
