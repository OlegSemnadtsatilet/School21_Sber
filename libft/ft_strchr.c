/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:14:10 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/19 14:06:42 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	a;
	int		i;

	str = (char *)s;
	a = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && a == '\0')
		return (&str[i]);
	return (NULL);
}
