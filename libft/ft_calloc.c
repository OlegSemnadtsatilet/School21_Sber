/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:11:45 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/18 16:11:46 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ftr_memset(void *b, int c, size_t len)
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

void	*ft_calloc(size_t count, size_t size)
{
	size_t	n;
	void	*buf;

	n = count * size;
	buf = malloc(n);
	if (buf)
		buf = ftr_memset(buf, 0, n);
	return (buf);
}
