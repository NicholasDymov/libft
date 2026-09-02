/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:50:48 by ndymov            #+#    #+#             */
/*   Updated: 2026/09/02 12:40:55 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_isspace(int c)
{
	return (c == ' ' || (unsigned)c - '\t' < 5);
}

int	ft_isascii(int c)
{
	return ((unsigned)c < 128);
}

int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

int	ft_isalpha(int c)
{
	return (((unsigned)c | 32) - 'a' < 26);
}

int	ft_isprint(int c)
{
	return ((unsigned)c - 32 < 95);
}
