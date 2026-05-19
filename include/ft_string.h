/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:40:18 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/19 16:36:13 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "libft.h"
# include <stddef.h> // size_t

int		ft_isspace(int c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *restrict dst, const char *restrict src);
char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n);
t_error	ft_strdup(char **dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
#endif
