/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_includes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:42:15 by bmaya             #+#    #+#             */
/*   Updated: 2022/02/12 16:06:16 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long long	str_to_nbr(const char *s)
{
	int			i;
	long long	number;

	i = 0;
	number = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			break ;
		number = number * 10 + (s[i] - '0');
		i++;
	}
	return (number);
}	

long long	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || \
		str[i] == '\r' || str[i] == '\n' || str[i] == 32)
			i++;
		if (str[i] == '-')
			return (str_to_nbr(&str[i + 1]) * -1);
		else if (str[i] == '+')
			return (str_to_nbr(&str[i + 1]));
		else
			return (str_to_nbr(&str[i]));
	}
	return (0);
}

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
