/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:13:07 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/21 10:15:05 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *(const unsigned char *)s != (unsigned char)c)
		s++;
	if (*(const unsigned char *)s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (*s)
	{
		if (*(const unsigned char *)s == (unsigned char)c)
			res = (char *)s;
		s++;
	}
	if (*(const unsigned char *)s == (unsigned char)c)
		res = (char *)s;
	return (res);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0 || *big == '\0')
		return (NULL);
	little_len = ft_strlen(little);
	while (*big && len >= little_len)
	{
		if (*big == *little && ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
