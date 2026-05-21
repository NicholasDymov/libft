/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndymov <ndymov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:37:25 by ndymov            #+#    #+#             */
/*   Updated: 2026/05/21 10:41:03 by ndymov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <limits.h>
#include <unistd.h>

#define INT_MIN_STR "-2147483648"
#define BUFF_SIZE 64

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	ft_putchar_fd('\n', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t	putnbr_buff(char *buff, int n);

void	ft_putnbr_fd(int n, int fd)
{
	char	buff[BUFF_SIZE];
	size_t	size;

	if (n == INT_MIN)
		return ((void)write(fd, INT_MIN_STR, ft_strlen(INT_MIN_STR)));
	if (n == 0)
		return ((void)write(fd, "0", 1));
	if (n < 0)
	{
		*buff = '-';
		size = putnbr_buff(buff + 1, -n) + 1;
	}
	else
	{
		size = putnbr_buff(buff, n);
	}
	write(fd, buff, size);
}

size_t	putnbr_buff(char *buff, int n)
{
	size_t	res;

	if (n < 10)
	{
		*buff = '0' + n;
		return (1);
	}
	res = putnbr_buff(buff, n / 10);
	buff[res] = '0' + n % 10;
	return (res + 1);
}
