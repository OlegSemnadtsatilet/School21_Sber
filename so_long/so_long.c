/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:24:07 by bmaya             #+#    #+#             */
/*   Updated: 2022/02/22 18:17:00 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_general	general;

	get_map_width_height(&general, argv[1]);
	save_map_to_var(&general, argv[1]);
	fill_map_counts(&general);
	general.mlx = mlx_init();
	general.window.width = general.map.width * 64;
	general.window.height = general.map.height * 64;
	general.window.ptr = mlx_new_window(general.mlx, general.window.width, \
	general.window.height, "Waha!");
	draw_map(general);
	mlx_key_hook(general.window., *key_input, &general);
	mlx_loop(general.mlx);
	return (0);
}

// gcc -lmlx -framework OpenGL -framework AppKit *.c *.h && ./a.out map.ber
