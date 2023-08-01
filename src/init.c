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
	data->keys.forward.keycode = KEY_W;
	data->keys.backward.keycode = KEY_S;
	data->keys.left.keycode = KEY_A;
	data->keys.right.keycode = KEY_D;
	data->keys.turn_left.keycode = KEY_LEFT;
	data->keys.turn_right.keycode = KEY_RIGHT;
	data->keys.esc.keycode = KEY_ESCAPE;
}

void	init_camera(t_data *data)
{
	data->camera.x = 0;
	data->camera.dir.x = 0;
	data->camera.dir.y = 0;
	data->camera.pos.x = 0;
	data->camera.pos.y = 0;
	data->camera.plane.x = 0;
	data->camera.plane.y = 0;
	data->camera.delta_dis.x = 0;
	data->camera.delta_dis.y = 0;
	data->camera.side_dis.x = 0;
	data->camera.side_dis.y = 0;
	data->map.cell.x = 0;
	data->map.cell.y = 0;
	data->player.step.x = 0;
	data->player.step.y = 0;
}

void	init_player(t_data *data)
{
	data->player.pos.x = 0;
	data->player.pos.y = 0;
	data->player.dir.x = 0;
	data->player.dir.y = -1;
	data->player.move_speed = 0.05;
	data->player.rotation_angle = 2.5;
	data->player.clockwise_rot = rot_matrixc(data->player.rotation_angle);
	data->player.cclockwise_rot = rot_matrixcc(data->player.rotation_angle);
}

void	init_data(t_data *data, char *filename)
{
	init_player(data);
	init_map(data, filename);
	init_rays(data);
	init_mlx(data);
	init_hooks(data);
	init_keys(data);
}
