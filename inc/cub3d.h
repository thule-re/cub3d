/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:45:23 by treeps            #+#    #+#             */
/*   Updated: 2023/07/13 11:45:23 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "vectors.h"
# include "keycodes.h"
# include <X11/X.h>
# include <math.h>
# include <stdlib.h>

# define HEIGHT 540
# define WIDTH  960
# define FOV 60.0

typedef struct s_tile {
	char	type;
}				t_tile;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}				t_img;

typedef struct s_texture {
	t_img	img;
	char	*path;
	int		height;
	int		width;
}				t_texture;

typedef struct s_map {
	t_tile		**map;
	int			width;
	int			height;
	t_texture	texture_no;
	t_texture	texture_so;
	t_texture	texture_we;
	t_texture	texture_ea;
	int			floor_color;
	int			ceiling_color;
}				t_map;

typedef struct s_key {
	int	is_pressed;
	int	keycode;
}				t_key;

typedef struct s_keyboard {
	t_key	forward;
	t_key	backward;
	t_key	left;
	t_key	right;
	t_key	turn_left;
	t_key	turn_right;
	t_key	esc;
}				t_keyboard;

typedef struct s_player {
	t_vec2	pos;
	t_vec2	dir;
	t_mat2	clockwise_rot;
	t_mat2	cclockwise_rot;
	double	move_speed;
	double	rotation_angle;
}				t_player;

typedef struct s_ray {
	t_vec2	dir;
	t_vec2	*pos;
}				t_ray;

typedef struct s_data {
	t_img		img;
	void		*mlx;
	void		*win;

	t_keyboard	keys;
	t_player	player;
	t_ray		rays[WIDTH];
	t_map		map;
}				t_data;

// init
void	init_data(t_data *data, char *filename);
void	init_mlx(t_data *data);
void	init_keys(t_data *data);
void	init_hooks(t_data *data);
void	init_player(t_data *data);
void	init_rays(t_data *data);
void	init_map(t_data *data, char *filename);

// hook
int		key_down(int k, t_data *data);
int		key_up(int k, t_data *data);
int		loop_hook(t_data *data);
int		destroy_hook(t_data *data);

//player
void	handle_keys(t_data *data);
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	turn_left(t_data *data);
void	turn_right(t_data *data);

// ray utils
void	update_ray_directions(t_data *data, t_mat2 rot);

// utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_pixel_value(t_img *img, int x, int y);
char	*trim(char *str, char c);
void	free_split(char **split);

// error
void	wrong_usage(void);
void	file_error(char *filename);
void	error(t_data *data, char *msg);

// cleanup
void	clean_exit(t_data *data);

// map parsing
int		parse_map(t_data *data, char **content);
int		check_valid(char **map);
void	fill_map(t_data *data, char **map);

// textures
int		load_texture(t_data *data, t_texture *texture);
void	draw_texture(t_img *img, t_texture texture, int x, int y);
void	draw_texture_column(t_img *img, t_texture tex, t_intersect sect);

// testing
void	test_render(t_data *data);
void	draw_box(t_data *data);
void	draw_rect(t_data *data, int x, int y, int size, int color);
void	clear_screen(t_data *data);
void	draw_rays(t_data *data);
void	draw_grid(t_data *data);

#endif
