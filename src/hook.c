/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:14:01 by treeps            #+#    #+#             */
/*   Updated: 2023/07/13 13:22:46 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_down(int k, t_data *data)
{
	//ft_printf("key pressed: %i\n", k);
	if (k == data->keys.esc.keycode)
		destroy_hook(data);
	else if (k == data->keys.forward.keycode)
		data->keys.forward.is_pressed = 1;
	else if (k == data->keys.backward.keycode)
		data->keys.backward.is_pressed = 1;
	else if (k == data->keys.left.keycode)
		data->keys.left.is_pressed = 1;
	else if (k == data->keys.right.keycode)
		data->keys.right.is_pressed = 1;
	else if (k == data->keys.turn_left.keycode)
		data->keys.turn_left.is_pressed = 1;
	else if (k == data->keys.turn_right.keycode)
		data->keys.turn_right.is_pressed = 1;
	return (k);
}

int	key_up(int k, t_data *data)
{
	//ft_printf("key released: %i\n", k);
	if (k == data->keys.forward.keycode)
		data->keys.forward.is_pressed = 0;
	else if (k == data->keys.backward.keycode)
		data->keys.backward.is_pressed = 0;
	else if (k == data->keys.left.keycode)
		data->keys.left.is_pressed = 0;
	else if (k == data->keys.right.keycode)
		data->keys.right.is_pressed = 0;
	else if (k == data->keys.turn_left.keycode)
		data->keys.turn_left.is_pressed = 0;
	else if (k == data->keys.turn_right.keycode)
		data->keys.turn_right.is_pressed = 0;
	return (k);
}

int	destroy_hook(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
}

int	loop_hook(t_data *data)
{
	handle_keys(data);
	test_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
