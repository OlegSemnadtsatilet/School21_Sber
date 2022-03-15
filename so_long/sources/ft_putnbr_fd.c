/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:14:01 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/14 19:35:09 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	f_putchar(int n, int fd)
{
	char	c;

	if (n < 10)
		c = n % 10 + '0';
	else if (n >= 10)
	{
		f_putchar(n / 10, fd);
		c = n % 10 + '0';
	}
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		f_putchar(n * (-1), fd);
	}
	else
		f_putchar(n, fd);
}
