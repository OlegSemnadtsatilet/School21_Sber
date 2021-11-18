/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:37:28 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/15 16:37:29 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list ap)
{
	char	simbol;

	simbol = (char)va_arg(ap, int);
	ft_putchar_fd(simbol, 1);
	return (1);
}
