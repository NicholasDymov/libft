/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:57:50 by ndymov            #+#    #+#             */
/*   Updated: 2026/06/01 13:42:20 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#ifndef SPEED

size_t	ft_strlen(const char *s)
{
	const char	*p = s;

	if (s == NULL)
		return (0);
	while (*p)
		p++;
	return (p - s);
}
#else

/* Magic numbers are bad, mkay? Don't be bad boys, don't use magic numbers. */

# if LONG_BIT == 32
#  define MASK01 0x01010101
#  define MASK80 0x80808080
# elif LONG_BIT == 64
#  define MASK01 0x0101010101010101
#  define MASK80 0x8080808080808080
# else
#  error Unsupported word size
# endif

static const char	*__find_null_word(const unsigned long *lp);

/* Start with aligning the pointer and then continue searching
 * for null terminator looking at a whole machine word. */
size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while ((uintptr_t)p & (sizeof(long) - 1))
	{
		if (!*p)
			return (p - s);
		p++;
	}
	return (__find_null_word((const unsigned long *)p) - s);
}

static const char	*__find_null_word(const unsigned long *lp)
{
	const char	*cp = (const char *)lp;

	while (!((*lp - MASK01) & ~*lp & MASK80))
	{
		lp++;
	}
	while (*cp)
		cp++;
	return (cp);
}
#endif
