/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:37:32 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/15 16:37:37 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_decimal_int(va_list ap)
{
	int	number;
	int	len_of_number;

	len_of_number = 0;
	number = va_arg(ap, int);
	ft_putnbr_fd(number, 1);
	if (number == -2147483648)
		return (11);
	else if (number < 0 && number != -2147483648)
	{
		number = number * (-1);
		len_of_number = 1;
	}
	while (number >= 10)
	{
		number = number / 10;
		len_of_number++;
	}
	return (len_of_number + 1);
}
