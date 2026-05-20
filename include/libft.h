/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:48:48 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/20 16:13:43 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef enum e_error
{
	OK,
	ERR_INVAL,
	ERR_NOMEM,
	ERR_EOF,
	ERR_UNCLOSED_QUOTE,
	ERR_PARSE,
}	t_error;

#endif
