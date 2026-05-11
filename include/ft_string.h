/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:40:18 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/11 17:14:17 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "libft.h"
# include <stddef.h> // size_t

t_error	ft_strdup(char **dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
#endif
