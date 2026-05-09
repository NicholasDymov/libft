/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:44:36 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/08 17:01:45 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>  // SIZE_MAX
#include <stdint.h> // SIZE_MAX
#include <stdlib.h> // malloc()

static int	vector_resize(t_vector *vec, size_t new_capacity)
{
	size_t	cap;
	void	**new_data;

	if (new_capacity > MAX_VECTOR_CAPACITY)
		return (errno = ENOMEM, 1);
	cap = 1;
	while (cap < new_capacity)
		cap <<= 1;
	if (cap > MAX_VECTOR_CAPACITY)
		cap = MAX_VECTOR_CAPACITY;
	new_data = malloc(sizeof(void *) * cap);
	if (new_data == NULL)
		return (1);
	vec->capacity = cap;
	if (vec->data != NULL)
	{
		(void)ft_memcpy(new_data, vec->data, sizeof(void *) * vec->size);
		free(vec->data);
	}
	vec->data = new_data;
	return (0);
}

int	vector_init(t_vector *vec, size_t capacity, void (*destroy)(void *))
{
	if (vec == NULL)
		return (1);
	vec->size = 0;
	vec->capacity = 0;
	vec->data = NULL;
	vec->destroy = destroy;
	if (capacity == 0)
		return (0);
	if (vector_resize(vec, capacity) == 0)
		return (0);
	return (1);
}

int	vector_push(t_vector *vec, void *new)
{
	if (vec == NULL)
		return (1);
	if (vec->size == vec->capacity && vector_resize(vec, vec->size + 1))
		return (1);
	vec->data[vec->size++] = new;
	return (0);
}

void	*vector_pop(t_vector *vec)
{
	if (vec == NULL || vec->size == 0)
		return (NULL);
	return (vec->data[--vec->size]);
}

void	vector_destroy(t_vector *vec)
{
	size_t	i;

	if (vec == NULL)
		return ;
	if (vec->destroy == NULL)
	{
		free(vec->data);
		return ;
	}
	i = 0;
	while (i < vec->size)
		vec->destroy(vec->data[i++]);
	free(vec->data);
}
