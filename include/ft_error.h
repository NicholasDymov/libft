/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:48:48 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/26 18:06:18 by ndymov           ###   ########.fr       */
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
	ERR_EOF,
	ERR_UNCLOSED_QUOTE,
	ERR_PARSE,
}	t_error;

#endif
