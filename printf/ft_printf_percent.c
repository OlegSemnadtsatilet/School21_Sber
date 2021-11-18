/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:38:42 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/15 16:38:45 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_percent(char percent)
{
	ft_putchar_fd(percent, 1);
	return (1);
}
