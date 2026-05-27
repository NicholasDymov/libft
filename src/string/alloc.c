/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:17:30 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 10:46:28 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdint.h>
#include <stdlib.h>

t_error	ft_strdup(char **dst, const char *s)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s) + 1;
	dup = malloc(size);
	if (dup == NULL)
		return (ERR_NOMEM);
	ft_strlcpy(dup, s, size);
	*dst = dup;
	return (OK);
}

char	*ft_strjoin(char const *s1, char const *s2, char sep)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 + 2 > SIZE_MAX - len2)
		return (NULL);
	res = malloc(len1 + len2 + 2);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	res[len1] = sep;
	ft_strlcpy(res + len1 + 1, s2, len2 + 1);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		size = 1;
	else if (len > size - start)
		size = size - start + 1;
	else
		size = len + 1;
	sub = malloc(size);
	if (sub == NULL)
		return (NULL);
	if (size > 1)
		ft_strlcpy(sub, s + start, size);
	else
		*sub = '\0';
	return (sub);
}
