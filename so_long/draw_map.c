/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:22:05 by bmaya             #+#    #+#             */
/*   Updated: 2022/02/22 15:14:08 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_texture(t_general general, int width, int height, char *path)
{
	general.texture.img = mlx_xpm_file_to_image(general.mlx, path, \
		&general.texture.img_width, &general.texture.img_height);
	general.texture.addr = mlx_get_data_addr(general.texture.img, \
		&general.texture.bits_per_pixel, &general.texture.line_width, \
		&general.texture.endian);
	mlx_put_image_to_window(general.mlx, general.window.ptr, \
		general.texture.img, width, \
		height);
	mlx_destroy_image(general.mlx, general.texture.img);
}

void	determ_and_draw_texture(t_general general, \
	char simbol, int width, int height)
{
	if (simbol == '1')
		draw_texture(general, width, height, "images/wall_1.xpm");
	else if (simbol == 'E')
		draw_texture(general, width, height, "images/door_1.xpm");
	else if (simbol == 'P')
		draw_texture(general, width, height, "images/eisenhorn_1.xpm");
	else if (simbol == 'C')
		draw_texture(general, width, height, "images/collectible_2.xpm");
	else if (simbol == 'O')
		draw_texture(general, width, height, "images/orc.xpm");
	else
		return ;
}

void	draw_objects(t_general general, int height_px, int width_px)
{
	height_px = 0;
	width_px = 0;
	while (height_px < general.window.height)
	{
		width_px = 0;
		while (width_px < general.window.width)
		{
			determ_and_draw_texture(general, \
				general.map.field[height_px / 64][width_px / 64], \
				width_px, height_px);
			width_px += 64;
		}
		height_px += 64;
	}
}

void	draw_map(t_general general)
{
	int	height_px;
	int	width_px;

	printf("%d", general.window.height);
	printf("%d", general.window.width);
	height_px = 0;
	width_px = 0;
	while (height_px < general.window.height)
	{
		width_px = 0;
		while (width_px < general.window.width)
		{
			draw_texture(general, width_px, height_px, "images/floor_3.xpm");
			width_px += 64;
		}
		height_px += 64;
	}
	draw_objects(general, height_px, width_px);
}
