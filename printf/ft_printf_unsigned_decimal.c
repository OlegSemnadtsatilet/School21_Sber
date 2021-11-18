/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_decimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:38:54 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/15 16:39:07 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ud_putchar(unsigned int n)
{
	char	c;

	if (n < 10)
		c = n % 10 + '0';
	else if (n >= 10)
	{
		ud_putchar(n / 10);
		c = n % 10 + '0';
	}
	write(1, &c, 1);
}

int	ft_printf_unsigned_decimal(va_list ap)
{
	unsigned int	number;
	int				len_of_number;

	number = va_arg(ap, unsigned int);
	ud_putchar(number);
	len_of_number = 0;
	while (number > 9)
	{
		number = number / 10;
		len_of_number++;
	}
	return (len_of_number + 1);
}
