/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:12:01 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/18 16:12:18 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	len_int(int n)
{
	int	i;
	int	negpos;

	if (n < 0 && n != -2147483648)
	{
		n = n * (-1);
		negpos = 1;
	}
	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (negpos == 1)
		return (i + 2);
	else
		return (i + 1);
}

void	positive(char *number, int len, int n)
{
	while (len-- >= 0)
	{
		number[len] = n % 10 + '0';
		n = n / 10;
	}
}

void	negative(char *number, int len, int n)
{
	n = n * (-1);
	while (len-- > 0)
	{
		number[len] = n % 10 + '0';
		n = n / 10;
	}
	number[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = len_int(n);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	if (n < 0 && n != -2147483648)
		negative(number, len, n);
	else
		positive(number, len, n);
	number[len] = '\0';
	return (number);
}
