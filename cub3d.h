/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:06:52 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 19:34:29 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "gnl/get_next_line.h"
# include <sys/time.h>
# include <stdio.h>
# include <math.h>

/* # define HEIGHT			720
# define WIDTH			1080
# define FOV			(M_PI / 3)
# define STEPANGLE		FOV / WIDTH
# define TANPI_6		0.57735026
# define PLANEDIST		(WIDTH / 2) / TANPI_6
# define GAMEBOXSIZE	64 */

# define HEIGHT			720
# define WIDTH			1080
# define FOV			1.0471975511965977
# define STEPANGLE		0.0009696273622191
# define TANPI_6		0.57735026
# define PLANEDIST		935.307450974387714
# define GAMEBOXSIZE	64

# define SPEED_MOUSE_MOVE	0.3
# define SPEED_PL_MOVE		200

# define SPACEVISIBLE	1000

# define MINIMAP_H		200
# define MINIMAP_W		250

# define BUTTONPRESS		4
# define BUTTONRELEASE		5
# define BUTTONMOVE			6
# define ON_DESTROY			17
# define ON_KEYDOWN			2
# define ON_KEYUP			3

# define ANIM_PERIOD		3

# define ISDOORAXIS			1
# define ISDOORORDINAT		2
# define ISSPRITE			0

# define IS_DOORAXIS	1
# define IS_DOORORDINAT	2
# define IS_SPRITE		0

enum e_keys
{
	a = 0,
	s,
	d,
	w = 13,
	left = 123,
	right,
	esc = 53
};

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}	t_point;

typedef struct s_img_info
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_p_pix;
	int		size_line;
	int		endian;
}	t_img_info;

typedef struct s_key
{
	float		press_x;
	float		mouse_move;
	int			y;
	int			x;
	int			direct;
}	t_key;

typedef struct s_game_window
{
	void		*mlx;
	void		*win;
	t_img_info	img;
}	t_game_window;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceilling;
}	t_textures;

typedef struct s_imgs
{
	t_img_info	north;
	t_img_info	south;
	t_img_info	west;
	t_img_info	east;
	t_img_info	cat[8];
	t_img_info	door[8];
	t_img_info	minotaur[8];
	t_img_info	player_icn;
}	t_imgs;

typedef struct s_two_dem_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_player_data
{
	t_vector	poz;
	float		direction;
}	t_player;

typedef struct s_slice_sprite_info
{
	float						dist;
	int							num_slice;
	int							is_door;
	t_img_info					*img;
	struct s_slice_sprite_info	*next;

}	t_slice_sp;

typedef struct s_sprite
{
	t_vector	poz;
	t_img_info	*tex;
	int			is_door;
	int			frame;
	int			animation_dir;
	float		dist_to_pl;
	float		left_angle;
	float		right_angle;
}	t_sprite;

typedef struct s_delta_time
{
	unsigned long	prev;
	unsigned long	pres;
}	t_dt;

typedef struct s_map_data
{
	char			**map;
	t_textures		texture;
	t_sprite		*sprites;
	t_game_window	window;
	t_imgs			imgs;
	t_player		pl;
	t_key			key;
	t_dt			time;
}	t_data;

typedef struct s_struct_for_clm_draw
{
	int	x_poz;
	int	num_column;
	int	heigth;
}	t_costil;

int				return_error(char *str);
int				exit_error(char *str);

int				check_format_map(char *map_name);
char			**copy_map_to_array(char *map_name, t_textures *textures);

int				ft_isspace(char c);
int				ft_atoi_base(char *str, int base);

t_player		init_player_direct_and_poz(char **map);

/* marugula chainges))) */
void			game(char **map, t_textures textures);
int				redrawing(t_data *data);

/* init_imgs.c */
void			init_sides_img(t_imgs *imgs, t_textures texture, void *mlx_ptr);
void			init_img(t_img_info *img, char	*texture_path, void *mlx_ptr);
void			creat_window_img(t_game_window *mlx);
void			init_cat_imgs(t_data *data);
void			init_minotaur_imgs(t_data *data);
void			init_door_imgs(t_data *data);
t_game_window	init_game_window(void);

/* paint_engine.c */
unsigned int	get_color_in_pixel(int x, int y, t_img_info img);
void			change_pixel_in_img(int x, int y, \
				t_img_info *img, unsigned int color);
void			draw_wall_column(t_costil info, t_img_info *winimg, \
				t_img_info texture);
t_costil		init_clm(int x_poz, int num_column, int heigth);
void			fill_floor_and_cell_window_img(t_img_info *img, \
				t_textures textures);
unsigned int	color_shift(int color, float intensive);
float			intensity(float prop);

/* raycast.c */
void			ray_cast(t_data *data);
int				is_wall_in_point(char **map, t_vector point);
float			distance(t_vector point_from, \
				t_vector point_to, float angle_ray);
float			distance_pyth(t_vector point_from, t_vector point_to);

/* draw_minimap.c */
void			draw_minimap(t_data *data);
int				max_len(char **map);

/* analyse/utils.c */
int				strarr_len(char **arr);

/* check_utils.c */
char			get_ch_in_dot(int x, int y, char **map);

/* find_pos_sprites.c */
void			init_sprites_struct(t_data *data);

/*init_loop_hook.c*/
void			init_loop_hook(t_data *data);

/* init_vector.c */
t_vector		init_vector(float x, float y);

/* time_works.c */
unsigned long	get_time(void);
float			deltatime_sec(t_dt time);
void			rewrite_time(t_dt *time);
float			deltatime_msec(t_dt time);

/* animation.c */
void			open_door_animation(t_sprite *door, t_vector pl);
void			sprite_animation(t_sprite *sprites, t_vector pl);

/* draw_minimap_utils.c */
float			shift_x(t_vector pixel, \
				t_player pl, int size_img, float size_cell);
float			shift_y(t_vector pixel, \
				t_player pl, int size_img, float size_cell);
int				max_len(char **map);
float			count_size_cell(char **map);

int				deal_destroy(void);
int				control_pl_dir(t_data *data);
void			init_control_key(t_data *data);
int				control_pl_poz(t_data *data);
int				control_key_down(int key, t_data *data);
int				control_key_up(int key, t_data *data);
int				mouse_move(int x, int y, t_data *data);

#endif