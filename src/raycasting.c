/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:00:29 by treeps            #+#    #+#             */
/*   Updated: 2023/07/31 09:17:26 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	perform_dda(t_data *data, int x)
{
	int			hit;
	t_intersect	sect;

	hit = 0;
	sect.ray = &data->rays[x];
	while (hit == 0)
	{
		if (data->camera.side_dis.x < data->camera.side_dis.y)
		{
			data->camera.side_dis.x += data->camera.delta_dis.x;
			data->map.cell.x += (int)data->player.step.x;
			data->camera.side = 0;
		}
		else
		{
			data->camera.side_dis.y += data->camera.delta_dis.y;
			data->map.cell.y += (int)data->player.step.y;
			data->camera.side = 1;
		}
		if (data->map.new_map[(int)data->map.cell.y][(int)data->map.cell.x])
			hit = 1;
	}
	sect.pos = data->map.cell;
	draw_ray(data, sect);
}

void	calculate_side_distance(t_data *data)
{
	data->map.cell.x = (int)data->camera.pos.x;
	data->map.cell.y = (int)data->camera.pos.y;
	if (data->rays->dir.x < 0)
	{
		data->player.step.x = -1;
		data->camera.side_dis.x = (data->camera.pos.x - data->map.cell.x) \
		* data->camera.delta_dis.x;
	}
	else
	{
		data->player.step.x = 1;
		data->camera.side_dis.x = (data->map.cell.x + 1.0 - data->camera.pos.x) \
		* data->camera.delta_dis.x;
	}
	if (data->rays->dir.y < 0)
	{
		data->player.step.y = -1;
		data->camera.side_dis.y = (data->camera.pos.y - data->map.cell.y) \
		* data->camera.delta_dis.y;
	}
	else
	{
		data->player.step.y = 1;
		data->camera.side_dis.y = (data->map.cell.y + 1.0 - data->camera.pos.y) \
		* data->camera.delta_dis.y;
	}
}

void	calculate_deltas(t_data *data, int x)
{
	double	cam_x;

	cam_x = 2 * x / (double)WIDTH - 1;
	data->camera.x = cam_x;
	if (data->rays[x].dir.x == 0)
		data->camera.delta_dis.x = INT_MAX;
	else
		data->camera.delta_dis.x = fabs(1 / data->rays[x].dir.x);
	if (data->rays[x].dir.y == 0)
		data->camera.delta_dis.y = INT_MAX;
	else
		data->camera.delta_dis.y = fabs(1 / data->rays[x].dir.y);
}

void	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		calculate_deltas(data, x);
		calculate_side_distance(data);
		perform_dda(data, x);
		x++;
	}
}
