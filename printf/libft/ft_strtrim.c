/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:14:44 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/20 16:05:46 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char const *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*answer;
	int		pos;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	pos = 0;
	while (char_in_set(set, s1[start]))
		start++;
	while (end > start && char_in_set(set, s1[end - 1]))
		end--;
	answer = (char *)malloc(sizeof(char) * (end - start + 1));
	if (answer == NULL)
		return (NULL);
	while (start < end)
		answer[pos++] = s1[start++];
	answer[pos] = 0;
	return (answer);
}
