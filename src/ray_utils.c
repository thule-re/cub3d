/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:36 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 15:07:36 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rays(t_data *data)
{
	int		i;
	t_vec2	dir;

	dir = vec2_rot_counter_clockwise(data->player.dir, FOV / 2);
	i = 0;
	while (i < WIDTH)
	{
		data->rays[i].pos = &data->player.pos;
		data->rays[i].dir = vec2_norm(dir);
		data->rays[i].idx = i;
		dir = vec2_rot_clockwise(dir, FOV / WIDTH);
		i++;
	}
}

void	update_ray_directions(t_data *data, t_mat2 rot)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		data->rays[i].dir = vec2_mrot(data->rays[i].dir, rot);
		data->rays[i].dir = vec2_norm(data->rays[i].dir);
		i++;
	}
}
