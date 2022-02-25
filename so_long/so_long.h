/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:04:37 by bmaya             #+#    #+#             */
/*   Updated: 2022/02/22 18:56:21 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h> 
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_xy
{
	int		x;
	int		y;
}	t_xy;

typedef struct s_window
{
	void	*ptr;
	int		height;
	int		width;
}	t_window;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		img_height;
	int		img_width;
	int		pos_height;
	int		pos_width;
	int		bits_per_pixel;
	int		line_width;
	int		endian;
}	t_texture;

typedef struct s_map
{
	char	**field;
	int		walls_cnt;
	int		floors_cnt;
	int		collectibles_cnt;
	int		exits_cnt;
	int		players_cnt;
	int		width;
	int		height;
}	t_map;

typedef struct s_general
{
	void		*mlx;
	t_texture	texture;
	t_map		map;
	t_window	window;
	t_xy		player_xy;
}	t_general;

char	*get_next_line(int fd);
void	*ft_memmove(void *dst, const void *src, size_t n);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

void	get_map_width_height(t_general *general, char *map_name);
void	save_map_to_var(t_general *general, char *map_name);
void	fill_map_counts(t_general *general);
void	draw_map(t_general general);

#endif