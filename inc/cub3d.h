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
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define HEIGHT 540
# define WIDTH  960
# define FOV 60.0

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
	double	move_speed;
}				t_player;

typedef struct s_ray {
	t_vec2	origin;
	t_vec2	dir;
}				t_ray;

typedef struct s_data {
	void		*img;
	void		*mlx;
	void		*win;
	char		*addr;

	int			bits_per_pixel;
	int			line_length;
	int			endian;

	t_keyboard	keys;
	t_player	player;
	t_ray		rays[WIDTH];
}				t_data;

// init
void	init_mlx(t_data *data);
void	init_keys(t_data *data);
void	init_hooks(t_data *data);
void	init_player(t_data *data);
void	init_rays(t_data *data);

// hook
int		key_hook(int k, t_data *data);
int		loop_hook(t_data *data);
int		destroy_hook(t_data *data);


// utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
