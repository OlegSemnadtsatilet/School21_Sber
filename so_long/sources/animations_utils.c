/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:38:38 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/14 13:18:37 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	init_imgs(t_general *general)
{
	general->imgs.floor = ft_strdup("images/floor_3.xpm");
	general->imgs.eisenhorn_r = ft_strdup("images/eisenhorn_1.xpm");
	general->imgs.eisenhorn_l = ft_strdup("images/eisenhorn_2.xpm");
	general->imgs.wall = ft_strdup("images/wall_1.xpm");
	general->imgs.clot = ft_strdup("images/clot_06.xpm");
	general->imgs.door = ft_strdup("images/door_1.xpm");
}
