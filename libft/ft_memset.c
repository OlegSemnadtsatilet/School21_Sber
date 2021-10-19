/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:13:53 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/18 16:13:54 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*buf;

	buf = (char *)b;
	i = 0;
	while (i < len)
	{
		buf[i] = c;
		i++;
	}
	b = (void *)buf;
	return (b);
}
