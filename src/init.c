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
	data->keys.forward.keycode = 119;
	data->keys.backward.keycode = 115;
	data->keys.left.keycode = 97;
	data->keys.right.keycode = 100;
	data->keys.turn_left.keycode = 65361;
	data->keys.turn_right.keycode = 65363;
	data->keys.esc.keycode = XK_Escape;
}

void	init_player(t_data *data)
{
	data->player.pos.x = 0;
	data->player.pos.y = 0;
	data->player.dir.x = 0;
	data->player.dir.y = -1;
	data->player.move_speed = 0.5;
}

void	init_data(t_data *data)
{
	init_mlx(data);
	init_hooks(data);
	init_keys(data);
	init_player(data);
	init_rays(data);
}
