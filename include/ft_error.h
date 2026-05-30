/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:48:48 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/30 16:23:41 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef enum e_error
{
	OK,
	ERR_INVAL,
	ERR_NOMEM,
	ERR_QUOTE,
	ERR_BRACE,
	ERR_PARSE,
	ERR_PIPE,
	ERR_FORK,
	ERR_WRITE,
	ERR_OPEN,
	ERR_CLOSE,
	ERR_DUP,
	ERR_ACCESS,
	ERR_NOENT,
	ERR_ISDIR,
	ERR_NOCMD,
	ERR_EXECVE,
	ERR_GETCWD,
	ERR_CHDIR,
	ERR_WAIT,
	ERR_ARG,
	ERR_HOME,
	ERR_EOF,
	ERR_ENV,
	ERR_TOO_MANY,
	ERR_NUMERIC,
	ERR_OVERFLOW,
	ERR_EXIT,
	ERR_MAX
}	t_error;

#endif
