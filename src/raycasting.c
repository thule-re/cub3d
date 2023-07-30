/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:00:29 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 15:00:29 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_dda(t_data *data)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->camera.side_dis.x < data->camera.side_dis.y)
		{
			data->camera.side_dis.x += data->camera.delta_dis.x;
			data->map.width += (int)data->player.step.x;
			data->camera.side = 0;
		}
		else
		{
			data->camera.side_dis.y += data->camera.delta_dis.y;
			data->map.height += (int)data->player.step.y;
			data->camera.side = 1;
		}
		if (data->map.new_map[data->map.width][data->map.height])
			if(data->map.new_map[data->map.width][data->map.height] == 1)
				hit = 1;
	}
}

void	calculate_side_distance(t_data *data)
{
	data->map.width = (int)data->camera.camera_pos.x;
	data->map.height = (int)data->camera.camera_pos.y;
	if(data->rays->dir.x < 0)
	{
		data->player.step.x = -1;
		data->camera.side_dis.x = (data->camera.camera_pos.x - data->map.width) * data->camera.delta_dis.x;
	}
	else
	{
		data->player.step.x = 1;
		data->camera.side_dis.x = (data->map.width + 1.0 - data->camera.camera_pos.x) * data->camera.delta_dis.x;
	}
	if(data->rays->dir.y < 0)
	{
		data->player.step.y = -1;
		data->camera.side_dis.y = (data->camera.camera_pos.y - data->map.height) * data->camera.delta_dis.y;
	}
	else
	{
		data->player.step.y = 1;
		data->camera.side_dis.y = (data->map.height + 1.0 - data->camera.camera_pos.y) * data->camera.delta_dis.y;
	}
}

void	calculate_deltas(t_data *data, int x)
{
	data->camera.camera_x = 2 * x / (double)WIDTH - 1;
	data->rays->dir.x = data->camera.camera_dir.x + data->camera.camera_plane.x * data->camera.camera_x;
	data->rays->dir.y = data->camera.camera_dir.y + data->camera.camera_plane.x * data->camera.camera_x;
	if (data->rays->dir.x == 0)
		data->camera.delta_dis.x = INT_MAX;
	else
		data->camera.delta_dis.x = fabs(1 / data->rays->dir.x);
	if (data->rays->dir.y == 0)
		data->camera.delta_dis.y = INT_MAX;
	else
		data->camera.delta_dis.y = fabs(1 / data->rays->dir.y);
}

void	raycasting(t_data *data)
{
	int 	x;

	x = 0;
	while (x < WIDTH)
	{
		calculate_deltas(data, x);
		calculate_side_distance(data);
		perform_dda(data);

		//draw_ray(data, x);
		x++;
	}
}