/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:44:36 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/11 11:01:58 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_vector.h"
#include <stdint.h> // SIZE_MAX
#include <stdlib.h> // malloc()

static t_error	vector_resize(t_vector *vec, size_t new_capacity)
{
	size_t	cap;
	void	**new_data;

	if (new_capacity > MAX_VECTOR_CAPACITY)
		return (ERR_NOMEM);
	cap = 1;
	while (cap < new_capacity)
		cap <<= 1;
	if (cap > MAX_VECTOR_CAPACITY)
		cap = MAX_VECTOR_CAPACITY;
	new_data = malloc(sizeof(void *) * cap);
	if (new_data == NULL)
		return (ERR_NOMEM);
	vec->capacity = cap;
	if (vec->data != NULL)
	{
		(void)ft_memcpy(new_data, vec->data, sizeof(void *) * vec->size);
		free(vec->data);
	}
	vec->data = new_data;
	return (OK);
}

t_error	vector_init(t_vector *vec, size_t capacity)
{
	t_error	err;

	if (vec == NULL)
		return (ERR_INVAL);
	vec->size = 0;
	vec->capacity = 0;
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

	if (vec == NULL)
		return (ERR_INVAL);
	if (vec->size == vec->capacity)
	{
		err = vector_resize(vec, vec->size + 1);
		if (err)
			return (err);
	}
	vec->data[vec->size++] = new;
	return (OK);
}

void	*vector_pop(t_vector *vec)
{
	if (vec == NULL)
		return (NULL);
	if (vec->size == 0)
		return (NULL);
	return (vec->data[--vec->size]);
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
		destroy(vec->data[i++]);
	free(vec->data);
}
