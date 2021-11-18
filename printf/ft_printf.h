/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:42:33 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/13 16:37:23 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	printf_for_type(va_list ap, char type_of_arg);

int	ft_printf_char(va_list ap);
int	ft_printf_string(va_list ap);
int	ft_printf_decimal_int(va_list ap);
int	ft_printf_unsigned_decimal(va_list ap);
int	ft_printf_percent(char percent);
int	ft_printf_low_hex_number(va_list ap);
int	ft_printf_up_hex_number(va_list ap);
int	ft_printf_void_pointer(va_list ap);

#endif