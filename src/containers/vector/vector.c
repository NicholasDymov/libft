/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:44:36 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/09 16:47:44 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"
#include "ft_memory.h"
#include "ft_vector.h"
#include <stdint.h> // SIZE_MAX
#include <stdlib.h> // malloc()

static t_error	vector_resize(t_vector *vec, size_t new_capacity)
{
	char	*new_data;

	new_capacity = po2_up(new_capacity);
	if (new_capacity == 0 || sizet_mult_overflow(vec->obj_size, new_capacity))
		return (ERR_INVAL);
	if (vec->obj_size * new_capacity > MAX_VECTOR_MEMORY)
		return (ERR_NOMEM);
	if (new_capacity == vec->capacity)
		return (OK);
	new_data = malloc(vec->obj_size * new_capacity);
	if (new_data == NULL)
		return (ERR_NOMEM);
	vec->capacity = new_capacity;
	if (vec->data != NULL)
	{
		(void)ft_memcpy(new_data, vec->data, vec->obj_size * vec->size);
		free(vec->data);
	}
	vec->data = new_data;
	return (OK);
}

t_error	vector_init(t_vector *vec, size_t obj_size, size_t capacity)
{
	t_error	err;

	if (vec == NULL || obj_size == 0 || sizet_mult_overflow(obj_size, capacity))
		return (ERR_INVAL);
	vec->size = 0;
	vec->capacity = 0;
	vec->obj_size = obj_size;
	vec->data = NULL;
	if (capacity == 0)
		return (OK);
	err = vector_resize(vec, capacity);
	if (err)
		return (err);
	return (OK);
}

t_error	vector_push(t_vector *vec, void *new)
{
	t_error	err;

	if (vec == NULL || new == NULL)
		return (ERR_INVAL);
	if (vec->size == vec->capacity)
	{
		err = vector_resize(vec, vec->size + 1);
		if (err)
			return (err);
	}
	ft_memcpy(vec->data + vec->obj_size * vec->size, new, vec->obj_size);
	vec->size++;
	return (OK);
}

t_error	vector_pop(t_vector *vec, void (*destroy)(void *))
{
	if (vec == NULL || vec->size == 0)
		return (ERR_INVAL);
	if (destroy != NULL)
		destroy(vec->data + vec->obj_size * (vec->size - 1));
	vec->size--;
	if (vec->size < vec->capacity >> 2)
		(void)vector_resize(vec, vec->capacity >> 1);
	return (OK);
}

void	vector_destroy(t_vector *vec, void (*destroy)(void *))
{
	size_t	i;

	if (vec == NULL)
		return ;
	if (destroy == NULL)
	{
		free(vec->data);
		return ;
	}
	i = 0;
	while (i < vec->size)
	{
		destroy(vec->data + vec->obj_size * i);
		i++;
	}
	free(vec->data);
}
