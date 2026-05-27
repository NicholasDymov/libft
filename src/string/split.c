/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:22:50 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/28 05:24:58 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

int	fill_arr(char **arr, char const *s, char c)
{
	char const	*cur;
	char const	*next;

	cur = s;
	while (*cur)
	{
		while (*cur == c)
			cur++;
		if (*cur == '\0')
			break ;
		next = cur;
		while (*next && *next != c)
			next++;
		*arr = malloc(next - cur + 1);
		if (*arr == NULL)
			return (1);
		ft_strlcpy(*arr++, cur, next - cur + 1);
		cur = next;
	}
	*arr = NULL;
	return (0);
}

size_t	split_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		size++;
		while (*s && *s != c)
			s++;
	}
	return (size + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	**cur;

	if (s == NULL)
		return (NULL);
	arr = ft_calloc(split_size(s, c), sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (fill_arr(arr, s, c))
	{
		cur = arr;
		while (*cur != NULL)
			free(*cur++);
		free(arr);
		return (NULL);
	}
	return (arr);
}
