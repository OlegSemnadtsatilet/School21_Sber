/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:10:17 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/18 16:10:28 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*mem;

	i = 0;
	while (s1[i] != '\0')
		i++;
	mem = (char *)malloc(sizeof(char) * (i + 1));
	if (!mem)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
