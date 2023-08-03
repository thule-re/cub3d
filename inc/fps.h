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
	data->camera.plane.x = 0;	//	X value of camera plane (what we see)
	data->camera.plane.y = 0;	//	Y value of camera plane (what we see)
	data->camera.delta_dis.x = 0;	//	X distance of the ray that has to travel from one X-side to the next.
	data->camera.delta_dis.y = 0;	//	Y distance of the ray that has to travel from one Y-side to the next.
	data->camera.side_dis.x = 0;	//	X distance of the ray that has to travel from player position to first X-side.
	data->camera.side_dis.y = 0;	//	Y distance of the ray that has to travel from player position to first Y-side.
	data->map.cell.x = 0;	//	X value of the cell of the map
	data->map.cell.y = 0;	//	Y value of the cell of the map
	data->camera.step.x = 0;	//	Direction our ray will move depending on the X value
	data->camera.step.y = 0;	//	Direction our ray will move depending on the Y value
	data->camera.side = 0;	//	A variable which will indicate whether an X-side or Y-side of a wall was hit.
}

void	perform_dda(t_data *data, int x)		// DDA = digital differential analyzer
{
	int hit;	// Variable to detect if the ray has hit a wall

	hit = 0;
	while (hit == 0)
	{
		if (data->camera.side_dis.x < data->camera.side_dis.y)
		{
			data->camera.side_dis.x += data->camera.delta_dis.x;
			data->map.cell.x += data->camera.step.x;
			data->camera.side = 0;
		}
		else
		{
			data->camera.side_dis.y += data->camera.delta_dis.y;
			data->map.cell.y += data->camera.step.y;
			data->camera.side = 1;
		}
		if (data->map.map[(int)data->map.cell.x][(int)data->map.cell.y].type == 1)
			hit = 1;
	}
}

void	calculate_side_distance(t_data *data)
{
	data->map.cell.x = (int)data->player.pos.x;		// INT value of the cell of the map we are currently in (X value)
	data->map.cell.y = (int)data->player.pos.y;		// INT value of the cell of the map we are currently in (Y value)
	if (data->rays->dir.x < 0)	//	If our ray direction has a negative X component
	{
		data->camera.step.x = -1;	//	Move -1 on the X-axis
		data->camera.side_dis.x = (data->player.pos.x - data->map.cell.x) * data->camera.delta_dis.x;
	}
	else
	{
		data->camera.step.x = 1;
		data->camera.side_dis.x = (data->map.cell.x + 1 - data->player.pos.x) * data->camera.delta_dis.x;
	}
	if (data->rays->dir.y < 0)
	{
		data->camera.step.y = -1;
		data->camera.side_dis.y = (data->player.pos.y - data->map.cell.y) * data->camera.delta_dis.y;
	}
	else
	{
		data->camera.step.y = 1;
		data->camera.side_dis.y = (data->map.cell.y + 1 - data->player.pos.y) * data->camera.delta_dis.y;
	}
}

void	calculate_deltas(t_data *data, int x)
{
	if (data->rays[x].dir.x == 0)
		data->camera.delta_dis.x = INT_MAX;		//	Reason why it's INT_MAX because ray would never intersect with "x" wall
	else
		data->camera.delta_dis.x = fabs(1 / data->rays[x].dir.x);
	if (data->rays[x].dir.y == 0)
		data->camera.delta_dis.y = INT_MAX;		//	Reason why it's INT_MAX because ray would never intersect with "y" wall
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
