/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:06:30 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/14 15:41:50 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static int	is_n_in_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*take_str_before_n(char *str)
{
	int		i;
	char	*cutted_str;

	i = 0;
	while (str[i + 1] != '\n' && str[i])
		i++;
	cutted_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!cutted_str)
		return (NULL);
	cutted_str[i + 1] = '\0';
	while (i >= 0)
	{
		cutted_str[i] = str[i];
		i--;
	}
	if (cutted_str[0] == '\0')
	{
		free(cutted_str);
		return (0);
	}
	return (cutted_str);
}

static char	*take_str_after_n(char *readed)
{
	int		i;
	int		j;
	char	*str_after_n;

	if (readed == NULL)
		return (0);
	i = 0;
	while (readed[i] != '\0' && readed[i] != '\n')
		i++;
	if (readed[i] == '\0')
	{
		free(readed);
		return (0);
	}
	str_after_n = (char *)malloc(sizeof(char) * (ft_strlen(readed) + 1 - i));
	if (str_after_n == NULL)
		return (0);
	i++;
	j = 0;
	while (readed[i])
		str_after_n[j++] = readed[i++];
	str_after_n[j] = '\0';
	free(readed);
	return (str_after_n);
}

char	*get_next_line(int fd)
{
	int			simbols_readed;
	char		*buf_str;
	static char	*readed_str = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf_str)
		return (0);
	simbols_readed = 1;
	while (simbols_readed != 0 && is_n_in_str(readed_str) != 1)
	{
		simbols_readed = read(fd, buf_str, BUFFER_SIZE);
		if (simbols_readed == -1)
			free(buf_str);
		if (simbols_readed == -1)
			return (0);
		buf_str[simbols_readed] = '\0';
		readed_str = ft_strjoin(readed_str, buf_str);
	}
	free(buf_str);
	buf_str = take_str_before_n(readed_str);
	readed_str = take_str_after_n(readed_str);
	return (buf_str);
}
