/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:38:38 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/11 14:11:30 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	init_imgs(t_general *general)
{
	general->imgs.floor = ft_strdup("images/floor_3.xpm");
	general->imgs.eisenhorn_r = ft_strdup("images/eisenhorn_1.xpm");
	general->imgs.eisenhorn_l = ft_strdup("images/eisenhorn_2.xpm");
	general->imgs.wall = ft_strdup("images/wall_1.xpm");
	general->imgs.clot = (char **)malloc(sizeof(char *) * 12);
	general->imgs.orc = (char **)malloc(sizeof(char *) * 20);
}

static void	imgs_mass_clot(t_general *general)
{
	general->imgs.clot[0] = ft_strdup("images/clot_01.xpm");
	general->imgs.clot[1] = ft_strdup("images/clot_02.xpm");
	general->imgs.clot[2] = ft_strdup("images/clot_03.xpm");
	general->imgs.clot[3] = ft_strdup("images/clot_04.xpm");
	general->imgs.clot[4] = ft_strdup("images/clot_05.xpm");
	general->imgs.clot[5] = ft_strdup("images/clot_06.xpm");
	general->imgs.clot[6] = ft_strdup("images/clot_07.xpm");
	general->imgs.clot[7] = ft_strdup("images/clot_08.xpm");
	general->imgs.clot[8] = ft_strdup("images/clot_09.xpm");
	general->imgs.clot[9] = ft_strdup("images/clot_10.xpm");
	general->imgs.clot[10] = ft_strdup("images/clot_11.xpm");
	general->imgs.clot[11] = ft_strdup("images/clot_12.xpm");
}

static void	imgs_mass_orc(t_general *general)
{
	general->imgs.orc[0] = ft_strdup("images/orc_01.xpm");
	general->imgs.orc[1] = ft_strdup("images/orc_02.xpm");
	general->imgs.orc[2] = ft_strdup("images/orc_03.xpm");
	general->imgs.orc[3] = ft_strdup("images/orc_04.xpm");
	general->imgs.orc[4] = ft_strdup("images/orc_05.xpm");
	general->imgs.orc[5] = ft_strdup("images/orc_06.xpm");
	general->imgs.orc[6] = ft_strdup("images/orc_07.xpm");
	general->imgs.orc[7] = ft_strdup("images/orc_08.xpm");
	general->imgs.orc[8] = ft_strdup("images/orc_09.xpm");
	general->imgs.orc[9] = ft_strdup("images/orc_10.xpm");
	general->imgs.orc[10] = ft_strdup("images/orc_11.xpm");
	general->imgs.orc[11] = ft_strdup("images/orc_12.xpm");
	general->imgs.orc[12] = ft_strdup("images/orc_13.xpm");
	general->imgs.orc[13] = ft_strdup("images/orc_14.xpm");
	general->imgs.orc[14] = ft_strdup("images/orc_15.xpm");
	general->imgs.orc[15] = ft_strdup("images/orc_16.xpm");
	general->imgs.orc[16] = ft_strdup("images/orc_17.xpm");
	general->imgs.orc[17] = ft_strdup("images/orc_18.xpm");
	general->imgs.orc[18] = ft_strdup("images/orc_19.xpm");
	general->imgs.orc[19] = ft_strdup("images/orc_20.xpm");
}

void	init_all_imgs(t_general *general)
{
	init_imgs(general);
	imgs_mass_clot(general);
	imgs_mass_orc(general);
}
