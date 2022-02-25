/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:12:49 by bmaya             #+#    #+#             */
/*   Updated: 2022/02/22 20:02:19 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Переделай эту чухню
void	make_move(t_general general, t_xy old_player_xy, t_xy next_player_xy)
{
	general.player_xy.grid[next_pos.y][next_pos.x] = 'P';
	general.player_xy.grid[old_pos.y][old_pos.x] = '0';
	general.player.step_count++;
	general.player.cur_pos = next_pos;
	draw_sprite_player(*prog, next_pos.x * 32, next_pos.y * 32);
	draw_sprite_ground(*prog, old_pos.x * 32, old_pos.y * 32);
	ft_printf("Steps -> %d\n", prog->player.step_count);
}

int	key_input(char *movement, t_general general)
{
	t_xy	next_xy;

	next_xy = general.player_xy;
	if (movement == "up")
		next_xy.y++;
	else if (movement == "down")
		next_xy.y--;
	else if (movement == "left")
		next_xy.x--;
	else if (movement == "right")
		next_xy.x++;
	if (general.player_xy.field[next_xy.y][next_xy.x] != '1' \
		&& general.player_xy.field[next_xy.y][next_xy.x] != 'O')
	{
		if (general.player_xy.field[next_xy.y][next_xy.x] == 'C')
		{
			draw_texture(general, next_xy.x * 64, next_xy.y * 64, \
				"images/floor_3.xpm");
			general.player_xy.collectibles_cnt--;
		}
		make_move(general, general.player_xy, next_xy);
	}
}	
