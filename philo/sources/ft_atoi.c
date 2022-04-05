/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:11:38 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/18 18:43:32 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	strtonbr(const char *s)
{
	int	i;
	int	number;

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

int	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || \
		str[i] == '\r' || str[i] == '\n' || str[i] == 32)
			i++;
		if (str[i] == '-')
			return (strtonbr(&str[i + 1]) * -1);
		else if (str[i] == '+')
			return (strtonbr(&str[i + 1]));
		else
			return (strtonbr(&str[i]));
	}
	return (0);
}
