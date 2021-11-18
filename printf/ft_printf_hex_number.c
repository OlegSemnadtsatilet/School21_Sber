/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:38:38 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/16 12:59:13 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_number(unsigned int hex_number, const char *base)
{
	char	pieces_of_hex[99];
	int		position_pieces;
	int		len_of_print;

	position_pieces = 0;
	len_of_print = 0;
	if (hex_number < 0)
		hex_number = 4294967295 + hex_number;
	while (hex_number > 15)
	{
		pieces_of_hex[position_pieces] = hex_number % 16;
		hex_number = hex_number / 16;
		position_pieces++;
	}
	pieces_of_hex[position_pieces] = hex_number;
	while (position_pieces >= 0)
	{
		ft_putchar_fd(base[(int)pieces_of_hex[position_pieces]], 1);
		len_of_print++;
		position_pieces--;
	}
	return (len_of_print);
}

int	ft_printf_low_hex_number(va_list ap)
{
	char	*base;
	int		hex_number;

	base = "0123456789abcdef";
	hex_number = va_arg(ap, int);
	return (print_hex_number(hex_number, base));
}

int	ft_printf_up_hex_number(va_list ap)
{
	char	*base;
	int		hex_number;

	base = "0123456789ABCDEF";
	hex_number = va_arg(ap, int);
	return (print_hex_number(hex_number, base));
}
