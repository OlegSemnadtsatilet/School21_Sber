/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:14:36 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/18 16:14:37 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char*s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (ss1[i] != ss2[i] || ss1[i] == 0 || ss2[i] == 0)
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
