/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:04:37 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/15 12:20:29 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h> 
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_imgs
{
	char	*floor;
	char	*eisenhorn_r;
	char	*eisenhorn_l;
	char	*wall;
	char	*clot;
	char	*door;
}	t_imgs;

typedef struct s_xy
{
	int		x;
	int		y;
}	t_xy;

typedef struct s_player
{
	t_xy	pos;
	int		steps;
}	t_player;

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
	t_player	player;
	t_imgs		imgs;
	int			anim_flag;
}	t_general;

char		*get_next_line(int fd);
void		*ft_memmove(void *dst, const void *src, size_t n);
int			ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s1);
char		*ft_itoa(int n);
void		ft_putnbr_fd(int n, int fd);

void		draw_map(t_general general);
void		draw_texture(t_general general, int width, int height, char *path);
void		find_player_pos(t_general *general);
void		make_move(t_general *general, t_xy old_pl_xy, t_xy next_pl_xy);
void		make_move_optional(t_general *general, t_xy old_pl_xy, \
	t_xy next_pl_xy, char *path);
int			player_move(char movement, t_general *general);
int			key_input(int key, void *param);
int			get_map_width_height(t_general *general, char *map_name);
void		save_map_to_var(t_general *general, char *map_name);
void		fill_map_counts(t_general *general);
int			ft_close(void);
void		moves_functions(t_general *general, t_xy next_xy, \
	int left_move_flag);
void		init_imgs(t_general *general);

#endif