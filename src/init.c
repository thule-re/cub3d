/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:50:57 by treeps            #+#    #+#             */
/*   Updated: 2023/07/13 12:50:57 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_down, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_up, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, destroy_hook, data);
	mlx_do_key_autorepeatoff(data->mlx);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
}

void	init_keys(t_data *data)
{
	data->keys.forward.is_pressed = 0;
	data->keys.backward.is_pressed = 0;
	data->keys.left.is_pressed = 0;
	data->keys.right.is_pressed = 0;
	data->keys.turn_left.is_pressed = 0;
	data->keys.turn_right.is_pressed = 0;
	data->keys.esc.is_pressed = 0;
	data->keys.forward.keycode = XK_W;
	data->keys.backward.keycode = XK_S;
	data->keys.left.keycode = XK_A;
	data->keys.right.keycode = XK_D;
	data->keys.turn_left.keycode = XK_Left;
	data->keys.turn_right.keycode = XK_Right;
	data->keys.esc.keycode = XK_Escape;
}

void	init_player(t_data *data)
{
	data->player.pos.x = 0;
	data->player.pos.y = 0;
	data->player.dir.x = 1;
	data->player.dir.y = 0;
	data->player.move_speed = 0.1;
}

void	init_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		data->rays[i].origin.x = data->player.pos.x;
		data->rays[i].origin.y = data->player.pos.y;
		data->rays[i].dir.x = cos((data->player.dir.x - FOV / 2) * M_PI / 180);
		data->rays[i].dir.y = sin((data->player.dir.y - FOV / 2) * M_PI / 180);
		i++;
	}
}
