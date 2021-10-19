/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:14:41 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/19 14:47:30 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	simbol;
	char			*str;

	str = (char *)s;
	len = 0;
	simbol = (unsigned char)c;
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] == simbol)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
