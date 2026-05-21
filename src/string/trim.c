/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:34:51 by ndymov            #+#    #+#             */
/*   Updated: 2025/09/11 11:47:56 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static char	*trim(unsigned char const *s1, size_t *trim_bitset);
void		fill_bitset(size_t *bitset, unsigned char const *set);
static char	*get_trimmed_start(unsigned char const *s, size_t *trim_bitset,
				size_t *len_trimmed);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trim_bitset[4];

	if (s1 == NULL || set == NULL)
		return (NULL);
	fill_bitset(trim_bitset, (unsigned char const *)set);
	return (trim((unsigned char const *)s1, trim_bitset));
}

static char	*trim(unsigned char const *s, size_t *trim_bitset)
{
	char const	*start;
	size_t		len_trimmed;
	char		*trimmed;

	start = get_trimmed_start(s, trim_bitset, &len_trimmed);
	trimmed = malloc(len_trimmed + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, start, len_trimmed + 1);
	return (trimmed);
}

static char	*get_trimmed_start(unsigned char const *s, size_t *trim_bitset,
		size_t *len_trimmed)
{
	unsigned char const	*p;
	unsigned char const	*left;
	unsigned char const	*right;

	p = s;
	left = NULL;
	right = s;
	while (*p)
	{
		if (!(trim_bitset[*p / 64] & (1ul << (*p % 64))))
		{
			if (left == NULL)
				left = p;
			right = p + 1;
		}
		p++;
	}
	if (left == NULL)
		left = s;
	*len_trimmed = right - left;
	return ((char *)left);
}

void	fill_bitset(size_t *bitset, unsigned char const *set)
{
	size_t	n;

	n = 4;
	while (n)
		bitset[--n] = 0;
	while (*set)
	{
		bitset[*set / 64] |= (1ul << (*set % 64));
		set++;
	}
}
