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
# include "mac_keycodes.h"
# include "libft.h"
# include <math.h>

# define HEIGHT 540
# define WIDTH  960

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

typedef struct s_data {
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// init
void	init_mlx(t_data *data);

// hook
int		key_hook(int k, t_data *data);
int		loop_hook(t_data *data);
int		destroy_hook(t_data *data);


// utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
