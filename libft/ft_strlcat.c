/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:14:23 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/20 15:15:33 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const	char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;
	char	*src_char;

	src_char = (char *)src;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src_char);
	if (n <= d_len)
		return (s_len + n);
	i = d_len;
	j = 0;
	while (i < n - 1 && src_char[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}
