/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:38:29 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/15 11:46:06 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	animation_draws(t_general *general, int o, int c, t_xy ij)
{
	if (general->map.field[ij.y][ij.x] == 'C')
	{
		draw_texture(*general, ij.x * 64, ij.y * 64, general->imgs.floor);
		draw_texture(*general, ij.x * 64, ij.y * 64, general->imgs.clot[c]);
	}
	else if (general->map.field[ij.y][ij.x] == 'O')
	{
		draw_texture(*general, ij.x * 64, ij.y * 64, general->imgs.floor);
		draw_texture(*general, ij.x * 64, ij.y * 64, general->imgs.orc[o]);
	}
}

int	animation(t_general *general)
{
	t_xy		ij;
	static int	c = 0;
	static int	o = 0;

	if (c++ == 11)
		c = 0;
	if (o++ == 19)
		o = 0;
	ij.y = 0;
	while (ij.y < general->map.height)
	{
		ij.x = 0;
		while (ij.x < general->map.width)
		{
			animation_draws(general, o, c, ij);
			ij.x++;
		}
		ij.y++;
	}
	usleep(50000);
	return (0);
}
