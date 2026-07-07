/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:07:45 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/07 11:43:11 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_vector.h"
#include <stdlib.h>

void	vector_clear(t_vector *vec)
{
	if (vec == NULL)
		return ;
	vec->size = 0;
}

void	*vector_back(t_vector *vec)
{
	if (vec == NULL || vec->size == 0)
		return (NULL);
	return (vec->data + vec->obj_size * (vec->size - 1));
}

void	*vector_get(t_vector *vec, size_t pos)
{
	if (vec == NULL || pos >= vec->size)
		return (NULL);
	return (vec->data + vec->obj_size * pos);
}

t_error	vector_foreach(t_vector *vec, t_error (*callback)(void *data,
			void *user_data), void *data)
{
	size_t	i;
	t_error	err;

	if (vec == NULL || callback == NULL)
		return (ERR_INVAL);
	i = 0;
	while (i < vec->size)
	{
		err = callback(vec->data + i * vec->obj_size, data);
		if (err)
			return (err);
		i++;
	}
	return (OK);
}

char	*vector_to_string(t_vector *vec)
{
	char	*str;
	size_t	size;

	if (vec == NULL)
		return (NULL);
	size = vec->obj_size * vec->size;
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	if (size > 0)
		ft_memcpy(str, vec->data, size);
	str[size] = '\0';
	return (str);
}
