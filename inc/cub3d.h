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
// # include "fps.h"
# include "keycodes.h"
# include <X11/X.h>
# include <math.h>
# include <stdlib.h>

# define HEIGHT 540
# define WIDTH  960
# define FOV 60.0
# define FPS 60
# define MOUSE_SENSITIVITY 0.3

// Struct prototypes
typedef struct s_ray		t_ray;
typedef struct s_intersect	t_intersect;
typedef struct s_tile		t_tile;
typedef struct s_img		t_img;
typedef struct s_texture	t_texture;
typedef struct s_map		t_map;
typedef struct s_key		t_key;
typedef struct s_mouse		t_mouse;
typedef struct s_keyboard	t_keyboard;
typedef struct s_player		t_player;
typedef struct s_data		t_data;

/// \brief Structure for a ray
/// \param dir Direction of the ray
/// \param pos Position of the ray
/// \param idx Index of the ray
typedef struct s_ray {
	t_vec2	dir;
	t_vec2	*pos;
	int		idx;
}				t_ray;

/// \brief Structure for an intersection
/// \param ray Ray that intersects
/// \param pos Position of the intersection
typedef struct s_intersect {
	t_ray	*ray;
	t_vec2	pos;
}				t_intersect;

/// \brief Structure for a tile
/// \param type Type of the tile
typedef struct s_tile {
	char	type;
}				t_tile;

/// \brief Structure for an image
/// \param img Pointer to the image
/// \param addr Address of the image
/// \param bpp Bits per pixel
/// \param length Length of the image
/// \param endian Endian of the image
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}				t_img;

/// \brief Structure for a texture
/// \param img Image of the texture
/// \param path Path to the texture
/// \param height Height of the texture
/// \param width Width of the texture
typedef struct s_texture {
	t_img	img;
	char	*path;
	int		height;
	int		width;
}				t_texture;

/// \brief Structure for a map
/// \param map Map
/// \param width Width of the map
/// \param height Height of the map
/// \param texture_no Texture for north walls
/// \param texture_so Texture for south walls
/// \param texture_we Texture for west walls
/// \param texture_ea Texture for east walls
/// \param floor_color Color of the floor
/// \param ceiling_color Color of the ceiling
typedef struct s_map {
	t_tile		**map;
	int			width;
	int			height;
	t_texture	texture_no;
	t_texture	texture_so;
	t_texture	texture_we;
	t_texture	texture_ea;
	int			floor;
	int			ceiling;
}				t_map;

/// \brief Structure for a key
/// \param is_pressed 1 if the key is pressed, 0 otherwise
/// \param keycode Keycode of the key
typedef struct s_key {
	int	is_pressed;
	int	keycode;
}				t_key;

/// \brief Structure for a mouse
/// \param pos Position of the mouse
/// \param lmb Left mouse button
/// \param mmb Middle mouse button
/// \param rmb Right mouse button
typedef struct s_mouse {
	t_key	lmb;
	t_key	mmb;
	t_key	rmb;
}				t_mouse;

/// \brief Structure for a keyboard
/// \param forward Key for moving forward
/// \param backward Key for moving backward
/// \param left Key for moving left
/// \param right Key for moving right
/// \param turn_left Key for turning left
/// \param turn_right Key for turning right
/// \param esc Key for exiting the program
typedef struct s_keyboard {
	t_key	forward;
	t_key	backward;
	t_key	left;
	t_key	right;
	t_key	turn_left;
	t_key	turn_right;
	t_key	sprint;
	t_key	esc;
}				t_keyboard;

/// \brief Structure for a player
/// \param pos Position of the player
/// \param dir Direction of the player
/// \param clockwise_rot Clockwise rotation matrix
/// \param cclockwise_rot Counter clockwise rotation matrix
/// \param move_speed Speed of the player
/// \param rotation_angle Rotation angle of the player
typedef struct s_player {
	t_vec2	pos;
	t_vec2	dir;
	t_mat2	clockwise_rot;
	t_mat2	cclockwise_rot;
	double	move_speed;
	double	rotation_angle;
}				t_player;

/// \brief Structure for the data
/// \param img Screen image
/// \param mlx Pointer to the mlx
/// \param win Pointer to the window
/// \param keys Keyboard
/// \param player Player
/// \param rays Array of rays
/// \param map Map
typedef struct s_data {
	t_img		img;
	void		*mlx;
	void		*win;

	t_keyboard	keys;
	t_mouse		mouse;
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
int		button_down(int k, int x, int y, t_data *data);
int		button_up(int k, int x, int y, t_data *data);
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
void	mouse_turn(t_data *data);
int		is_in_hitbox(t_map map, t_vec2 pos);

// ray utils
void	update_ray_directions(t_data *data, t_mat2 rot);

// utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_pixel_value(t_img *img, int x, int y);
char	*trim(char *str, char c);
void	free_split(char **split);
double	max(double a, double b);

// error
void	wrong_usage(void);
void	file_error(char *filename, t_data *data);
void	error(t_data *data, char *msg);

// cleanup
void	free_map(t_data *data);

// map parsing
int		parse_map(t_data *data, char **content);
int		check_valid(char **map);
void	fill_map(t_data *data, char **map);

// textures
void	draw_ray(t_data *data, t_intersect intersect);
int		load_textures(t_data *data);
void	draw_column(t_data *data, t_texture tex, t_intersect sect, int type);

// minimap
void	draw_minimap(t_data *data);
void	draw_tile(t_data *data, int x, int y, int color);

// raycasting
void	raycasting(t_data *data);
int		is_wall(t_map map, t_vec2 pos);

#endif
