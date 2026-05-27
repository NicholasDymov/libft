/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:48:48 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/27 08:41:12 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef enum e_error
{
	OK,
	ERR_INVAL,
	ERR_NOMEM,
	ERR_EXECVE,
	ERR_PIPE,
	ERR_FORK,
	ERR_WAIT,
	ERR_EOF,
	ERR_UNCLOSED_QUOTE,
	ERR_PARSE,
}	t_error;

#endif
