/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:22:50 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/10 14:44:59 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_int.h"
#include "ft_string.h"
#include "ft_vector.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

static void	free_ptr(void *ptr)
{
	free(*(void **)ptr);
}

static t_error	push_split(t_vector *vec, const char *start, size_t len)
{
	char	*str;

	str = malloc(len + 1);
	if (str == NULL)
		return (ERR_NOMEM);
	(void)ft_strlcpy(str, start, len + 1);
	if (vector_push(vec, &str))
		return (free(str), ERR_NOMEM);
	return (OK);
}

t_error	ft_split(t_vector *vec, const char *s, char sep, size_t maxsplit)
{
	const char	*start;

	if (s == NULL || vec == NULL || !ft_isascii(sep))
		return (ERR_INVAL);
	if (vector_init(vec, sizeof(char *), ft_min(maxsplit, 7) + 1))
		return (ERR_NOMEM);
	start = s;
	while (*s)
	{
		if (*s == sep && vec->size < maxsplit)
		{
			if (push_split(vec, start, s - start))
				return (vector_destroy(vec, free_ptr), ERR_NOMEM);
			start = s + 1;
		}
		s++;
	}
	if (push_split(vec, start, s - start))
		return (vector_destroy(vec, free_ptr), ERR_NOMEM);
	return (OK);
}

t_error	ft_split_words(t_vector *vec, const char *s, int (*issep)(int),
		size_t maxsplit)
{
	const char	*next;

	if (s == NULL || vec == NULL || issep == NULL)
		return (ERR_INVAL);
	if (vector_init(vec, sizeof(char *), ft_min(maxsplit, 7) + 1))
		return (ERR_NOMEM);
	while (*s)
	{
		while (*s && issep(*s))
			s++;
		if (*s == '\0')
			break ;
		next = s + 1;
		while (*next && (!issep(*next) || vec->size == maxsplit))
			next++;
		if (push_split(vec, s, next - s))
			return (vector_destroy(vec, free_ptr), ERR_NOMEM);
		s = next;
	}
	return (OK);
}
