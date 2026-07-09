/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:01:41 by ndymov            #+#    #+#             */
/*   Updated: 2026/07/09 13:07:16 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array(void **arr, void (*destroy)(void *))
{
	void	**ptr;

	if (arr == NULL)
		return ;
	if (destroy == NULL)
	{
		free(arr);
		return ;
	}
	ptr = arr;
	while (*ptr)
	{
		destroy(*ptr);
		ptr++;
	}
	free(arr);
}
