/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:24:07 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/15 11:41:05 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	check_edge_walls(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if ((y == 0 || y == map.height - 1) && map.field[y][x] != '1')
				return (1);
			if ((x == 0 || x == map.width - 1) && map.field[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_map_simbols(t_map	map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.field[y][x] != '1' && map.field[y][x] != '0' \
			&& map.field[y][x] != 'C' && map.field[y][x] != 'E' \
			&& map.field[y][x] != 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_errors(t_general *general, char **argv)
{
	int		flag;

	flag = 0;
	if (general->map.players_cnt != 1 || general->map.exits_cnt == 0 \
		|| general->map.collectibles_cnt == 0)
		flag = 1;
	if (get_map_width_height(general, argv[1]) == 1 \
	|| check_edge_walls(general->map) == 1 \
	|| check_map_simbols(general->map) == 1)
		flag = 1;
	if (check_edge_walls(general->map) == 1)
		flag = 1;
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r' \
		|| argv[1][ft_strlen(argv[1]) - 2] != 'e' \
		|| argv[1][ft_strlen(argv[1]) - 3] != 'b' \
		|| argv[1][ft_strlen(argv[1]) - 4] != '.')
		flag = 1;
	if (flag == 1)
		write(1, "Error\n", 6);
	return (flag);
}

int	ft_close(void)
{
	write(1, "Game was closed\n", 16);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_general	general;

	if (argc != 2)
		return (0);
	general.player.steps = 0;
	init_imgs(&general);
	get_map_width_height(&general, argv[1]);
	save_map_to_var(&general, argv[1]);
	fill_map_counts(&general);
	if (check_errors(&general, argv) == 1)
		exit (1);
	general.mlx = mlx_init();
	general.window.width = general.map.width * 64;
	general.window.height = general.map.height * 64;
	general.window.ptr = mlx_new_window(general.mlx, general.window.width, \
		general.window.height, "Waha!");
	draw_map(general);
	mlx_key_hook(general.window.ptr, *key_input, &general);
	mlx_hook(general.window.ptr, 17, 0, ft_close, 0);
	mlx_loop(general.mlx);
	return (0);
}

// gcc -lmlx -framework OpenGL -framework AppKit *.c *.h && ./a.out map.ber
