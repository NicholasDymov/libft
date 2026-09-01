/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:16:05 by ndymov            #+#    #+#             */
/*   Updated: 2026/09/01 12:22:55 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_io.h"
#include "ft_vector.h"
#include <unistd.h>

static t_error	read_to_buffer(int fd, t_read_buffer *buff)
{
	ssize_t	n;

	if (buff->pos < buff->end)
		return (OK);
	n = read(fd, buff->buff, GNL_BUFFER_SIZE);
	buff->pos = 0;
	buff->end = 0;
	if (n < 0)
		return (ERR_READ);
	else if (n == 0)
		return (ERR_EOF);
	else
		buff->end = n;
	return (OK);
}

static t_error	consume_buffer(t_read_buffer *buff, t_vector *vec)
{
	while (buff->pos < buff->end)
	{
		if (vector_push(vec, (void *)(buff->buff + buff->pos)))
			return (ERR_NOMEM);
		if (buff->buff[buff->pos++] == '\n')
			return (OK);
	}
	return (ERR_NEWLINE);
}

char	*get_next_line(int fd)
{
	static t_read_buffer	buff[GNL_MAX_FDS];
	t_vector				vec;
	char					*line;
	t_error					err;

	if (fd < 0 || fd >= GNL_MAX_FDS || read_to_buffer(fd, buff + fd))
		return (NULL);
	if (vector_init(&vec, sizeof(char), GNL_VECTOR_INIT_CAP) != OK)
		return (NULL);
	while (read_to_buffer(fd, buff + fd) == OK)
	{
		err = consume_buffer(buff + fd, &vec);
		if (err == ERR_NEWLINE)
			continue ;
		else if (err)
			return (vector_destroy(&vec, NULL), NULL);
		else
			break ;
	}
	line = NULL;
	if (vec.size > 0)
		line = vector_to_string(&vec);
	return (vector_destroy(&vec, NULL), line);
}
