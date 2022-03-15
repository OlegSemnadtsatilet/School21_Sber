/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:10:22 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/14 16:13:59 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	get_map_width_height(t_general *general, char *map_name)
{
	int		fd;
	char	*line;

	general->map.height = 0;
	general->map.width = 0;
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	general->map.width = ft_strlen(line);
	while (line)
	{
		general->map.height++;
		free(line);
		line = get_next_line(fd);
		if (general->map.width != ft_strlen(line) && line)
		{
			free(line);
			close(fd);
			return (1);
		}
	}
	free(line);
	close(fd);
	return (0);
}

void	save_map_to_var(t_general *general, char *map_name)
{
	int		fd;
	int		line_cnt;

	line_cnt = 0;
	general->map.field = malloc(sizeof(char *) * \
	(general->map.height + 0));
	fd = open(map_name, O_RDONLY);
	while (line_cnt < general->map.height)
	{
		general->map.field[line_cnt] = get_next_line(fd);
		line_cnt++;
	}
}

static void	count_simbols(t_general *general, char simbol)
{
	if (simbol == 'C')
		general->map.collectibles_cnt++;
	if (simbol == 'E')
		general->map.exits_cnt++;
	if (simbol == 'P')
		general->map.players_cnt++;
}

static void	reset_map_cnts(t_general *general)
{
	general->map.collectibles_cnt = 0;
	general->map.exits_cnt = 0;
	general->map.players_cnt = 0;
}

void	fill_map_counts(t_general *general)
{
	int	str_cnt;
	int	col_cnt;

	str_cnt = 0;
	col_cnt = 0;
	reset_map_cnts(general);
	while (str_cnt < general->map.height)
	{
		while (col_cnt <= general->map.width)
		{
			count_simbols(general, general->map.field[str_cnt][col_cnt]);
			col_cnt++;
		}
		str_cnt++;
		col_cnt = 0;
	}
}
