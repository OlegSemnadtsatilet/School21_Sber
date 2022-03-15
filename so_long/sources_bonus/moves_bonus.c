/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:12:49 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/12 18:46:06 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	find_player_pos(t_general *general)
{
	int	x;
	int	y;

	y = 0;
	while (general->map.field[y])
	{
		x = 0;
		while (general->map.field[y][x])
		{
			if (general->map.field[y][x] == 'P')
			{
				general->player.pos.x = x;
				general->player.pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}	

void	make_move(t_general *general, t_xy old_pl_xy, t_xy next_pl_xy)
{
	general->map.field[next_pl_xy.y][next_pl_xy.x] = 'P';
	general->map.field[old_pl_xy.y][old_pl_xy.x] = '0';
	general->player.steps++;
	general->player.pos = next_pl_xy;
	draw_texture(*general, next_pl_xy.x * 64, next_pl_xy.y * 64, \
		general->imgs.eisenhorn_r);
	draw_texture(*general, old_pl_xy.x * 64, old_pl_xy.y * 64, \
		general->imgs.floor);
}

void	make_move_optional(t_general *general, t_xy old_pl_xy, \
	t_xy next_pl_xy, char *path)
{
	draw_texture(*general, next_pl_xy.x * 64, next_pl_xy.y * 64, path);
	draw_texture(*general, old_pl_xy.x * 64, old_pl_xy.y * 64, \
		general->imgs.floor);
	general->map.field[next_pl_xy.y][next_pl_xy.x] = 'P';
	general->map.field[old_pl_xy.y][old_pl_xy.x] = '0';
	general->player.steps++;
	general->player.pos = next_pl_xy;
}

int	player_move(char movement, t_general *general)
{
	t_xy	next_xy;
	int		left_move_flag;

	left_move_flag = 0;
	next_xy = general->player.pos;
	if (movement == 'u')
		next_xy.y++;
	else if (movement == 'd')
		next_xy.y--;
	else if (movement == 'l')
	{
		next_xy.x--;
		left_move_flag = 1;
	}
	else if (movement == 'r')
		next_xy.x++;
	moves_functions(general, next_xy, left_move_flag);
	return (0);
}

int	key_input(int key, void *param)
{
	t_general	*general;

	general = (t_general *) param;
	find_player_pos(general);
	if (key == 1)
		player_move('u', general);
	else if (key == 13)
		player_move('d', general);
	else if (key == 0)
		player_move('l', general);
	else if (key == 2)
		player_move('r', general);
	else if (key == 53)
	{	
		ft_close();
		exit (1);
	}
	return (0);
}
