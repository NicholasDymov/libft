/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 10:39:32 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/17 13:13:33 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

# include <stdint.h>

uint64_t	po2_up(uint64_t x);
uint64_t	po2_down(uint64_t x);

uint64_t	multiple_up(uint64_t x, uint64_t div);
uint64_t	multiple_down(uint64_t x, uint64_t div);

uint64_t	multiple_po2_up(uint64_t x, uint64_t div);
uint64_t	multiple_po2_down(uint64_t x, uint64_t div);

#endif
