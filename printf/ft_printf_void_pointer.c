/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:37:01 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/15 16:37:02 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_pointer_hex(unsigned long long hex_number, char *base)
{
	char	pieces_of_hex[99];
	int		position_pieces;
	int		len_of_print;

	position_pieces = 0;
	len_of_print = 0;
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

int	ft_printf_void_pointer(va_list ap)
{
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(ap, void *);
	if (!pointer)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		return (ft_printf_pointer_hex(pointer, "0123456789abcdef") + 2);
	}
}
