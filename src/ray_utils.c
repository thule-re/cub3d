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

void	update_ray_origins(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		data->rays[i].origin.x = data->player.pos.x;
		data->rays[i].origin.y = data->player.pos.y;
		i++;
	}
}

void	update_ray_directions(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		data->rays[i].dir.x = cos((data->player.dir.x - FOV / 2) * M_PI / 180);
		data->rays[i].dir.y = sin((data->player.dir.y - FOV / 2) * M_PI / 180);
		i++;
	}
}
