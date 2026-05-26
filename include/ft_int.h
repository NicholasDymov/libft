/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 10:39:32 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/26 11:36:22 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

# include <stddef.h>
# include <stdint.h>

int			ft_atoi(const char *s);
int64_t		ft_atou(const char *s);

char		*ft_itoa(int n);
char		*ft_utoa(uint64_t n);

size_t		ft_itobuff(int n, char *buff);
size_t		ft_utobuff(uint64_t n, char *buff);

uint64_t	po2_up(uint64_t x);
uint64_t	po2_down(uint64_t x);

uint64_t	multiple_up(uint64_t x, uint64_t div);
uint64_t	multiple_down(uint64_t x, uint64_t div);

uint64_t	multiple_po2_up(uint64_t x, uint64_t div);
uint64_t	multiple_po2_down(uint64_t x, uint64_t div);

int			sizet_mult_overflow(size_t x, size_t y);

#endif
