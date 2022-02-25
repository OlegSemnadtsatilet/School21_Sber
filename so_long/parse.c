/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:10:22 by bmaya             #+#    #+#             */
/*   Updated: 2022/02/22 19:56:13 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_width_height(t_general *general, char *map_name)
{
	int		fd;
	char	*line;

	general->map.height = 0;
	general->map.width = 0;
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		general->map.width = ft_strlen(line);
		general->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	// Убрать
	printf("%d\n", general->map.width);
	printf("%d\n", general->map.height);
	// Убрать
	close(fd);
}

void	save_map_to_var(t_general *general, char *map_name)
{
	int		fd;
	int		line_cnt;
	// Убрать
	int		i; // Убрать
	// Убрать
	line_cnt = 0;
	general->map.field = malloc(sizeof(char *) * \
	(general->map.height + 1));
	fd = open(map_name, O_RDONLY);
	while (line_cnt <= general->map.height)
	{
		general->map.field[line_cnt] = get_next_line(fd);
		line_cnt++;
	}
	// Убрать
	line_cnt = 0;
	while (line_cnt < general->map.height)
	{
		printf("%s", general->map.field[line_cnt]);
		line_cnt++;
	}
	printf("\n");
	// Убрать
}

static void	count_simbols(t_general *general, char simbol)
{
	if (simbol == '1')
		general->map.walls_cnt++;
	if (simbol == '0')
		general->map.floors_cnt++;
	if (simbol == 'C')
		general->map.collectibles_cnt++;
	if (simbol == 'E')
		general->map.exits_cnt++;
	if (simbol == 'P')
		general->map.players_cnt++;
}

static void	reset_map_cnts(t_general *general)
{
	general->map.walls_cnt = 0;
	general->map.floors_cnt = 0;
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
	// Udoli
	printf("Walls: %d\n", general->map.walls_cnt);
	printf("Spaces: %d\n", general->map.floors_cnt);
	printf("Coins: %d\n", general->map.collectibles_cnt);
	printf("Exits: %d\n", general->map.exits_cnt);
	printf("Players: %d\n", general->map.players_cnt);
	// Udoli
}
