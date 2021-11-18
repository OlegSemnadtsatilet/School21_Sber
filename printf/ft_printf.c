/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:42:36 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/15 14:00:43 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_nontype(char character, int position)
{
	write(1, &character, 1);
	position++;
}

static int	get_type_of_arg(int type_of_arg)
{
	if (type_of_arg != '\0')
	{
		if (type_of_arg == 'c')
			return (type_of_arg);
		else if (type_of_arg == 's')
			return (type_of_arg);
		else if (type_of_arg == 'p')
			return (type_of_arg);
		else if (type_of_arg == 'd')
			return (type_of_arg);
		else if (type_of_arg == 'i')
			return (type_of_arg);
		else if (type_of_arg == 'u')
			return (type_of_arg);
		else if (type_of_arg == 'x')
			return (type_of_arg);
		else if (type_of_arg == 'X')
			return (type_of_arg);
		else if (type_of_arg == '%')
			return (type_of_arg);
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		position;
	int		returned_len;
	char	type_of_arg;
	va_list	ap;

	va_start(ap, str);
	position = 0;
	returned_len = 0;
	while (str[position] != '\0')
	{
		if (str[position] == '%')
		{
			type_of_arg = get_type_of_arg(str[position + 1]);
			returned_len += printf_for_type(ap, type_of_arg);
			position += 1;
		}
		else
		{
			ft_print_nontype(str[position], position);
			returned_len++;
		}
		position++;
	}
	va_end(ap);
	return (returned_len);
}
