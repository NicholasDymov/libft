/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:14:24 by ndymov            #+#    #+#             */
/*   Updated: 2026/09/01 12:18:09 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 4096
# endif

# ifndef GNL_MAX_FDS
#  define GNL_MAX_FDS 16
# endif

# ifndef GNL_VECTOR_INIT_CAP
#  define GNL_VECTOR_INIT_CAP 64
# endif

# include <stddef.h>

typedef struct s_read_buffer
{
	size_t	pos;
	size_t	end;
	char	buff[GNL_BUFFER_SIZE];
}			t_read_buffer;

char		*get_next_line(int fd);

#endif
