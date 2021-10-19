/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:13:49 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/18 16:13:50 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstc;
	char	*srcc;

	if (!dst && !src)
		return (NULL);
	dstc = (char *)dst;
	srcc = (char *)src;
	if (srcc >= dstc)
	{
		i = 0;
		while (i < n)
		{
			dstc[i] = srcc[i];
			i++;
		}
	}	
	else
		while (n-- > 0)
			dstc[n] = srcc[n];
	dst = (void *)dstc;
	return (dst);
}
