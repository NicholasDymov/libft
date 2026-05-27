/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 08:58:26 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 11:28:39 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == s2)
		return (0);
	while (*s1 && (unsigned char)*s1 == (unsigned char)*s2)
	{
		s1++;
		s2++;
	}
	return (((unsigned char)*s1 - (unsigned char)*s2));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == s2 || n == 0)
		return (0);
	while (--n && *s1 && (unsigned char)*s1 == (unsigned char)*s2)
	{
		s1++;
		s2++;
	}
	return (((unsigned char)*s1 - (unsigned char)*s2));
}
