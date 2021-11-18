/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:11:25 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/20 16:08:10 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*new_str(char const *s, char c)
{
	int		j;

	j = 0;
	while (s[j] != c && s[j])
		j++;
	return (ft_substr(s, 0, j));
}

static char	**leak_protect(char **arr, int saved_words)
{
	int	i;

	i = 0;
	while (i < saved_words)
	{
		free(arr[i]);
		i++;
	}
	return (NULL);
}

static char	**splitting(char **arr, char const *s, char c, int words)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			arr[j] = new_str(&s[i], c);
			if (!arr[j])
				return (leak_protect(arr, j));
			while (s[i] != c && s[i])
				i++;
		}
		j++;
	}
	arr[j] = (void *)0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	words = words_counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = splitting(arr, s, c, words);
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
