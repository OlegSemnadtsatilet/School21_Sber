/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_for_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:39:24 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/15 16:39:25 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_for_type(va_list ap, char type_of_arg)
{
	if (type_of_arg == 'c')
		return (ft_printf_char(ap));
	else if (type_of_arg == 's')
		return (ft_printf_string(ap));
	else if (type_of_arg == 'p')
		return (ft_printf_void_pointer(ap));
	else if (type_of_arg == 'd')
		return (ft_printf_decimal_int(ap));
	else if (type_of_arg == 'i')
		return (ft_printf_decimal_int(ap));
	else if (type_of_arg == 'u')
		return (ft_printf_unsigned_decimal(ap));
	else if (type_of_arg == 'x')
		return (ft_printf_low_hex_number(ap));
	else if (type_of_arg == 'X')
		return (ft_printf_up_hex_number(ap));
	else if (type_of_arg == '%')
		return (ft_printf_percent('%'));
	return (0);
}
