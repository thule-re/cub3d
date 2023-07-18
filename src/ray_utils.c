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
	t_vec2	delta;
	t_vec2	dir;

	if (WIDTH % 2)
		exit(1);
	delta = vec2_mrot(data->player.dir, g_rot90);
	delta = vec2_mul(delta, FOV / WIDTH);
	dir = data->player.dir;
	i = 0;
	while (i < WIDTH / 2)
	{
		dir = vec2_add(dir, delta);
		data->rays[i].dir = vec2_norm(dir);
		i++;
	}
	dir = data->player.dir;
	while (i < WIDTH)
	{
		dir = vec2_sub(dir, delta);
		data->rays[i].dir = vec2_norm(dir);
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
