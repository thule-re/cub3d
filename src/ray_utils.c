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

/// \brief Initialize the rays
/// \param data Pointer to the main data structure
/// \return none
void	init_rays(t_data *data)
{
	int		i;
	t_vec2	dir;
	t_vec2	tmp;
	double	len;
	t_vec2	step;

	dir = vec2_rot_counter_clockwise(data->player.dir, FOV / 2);
	tmp = vec2_rot_clockwise(data->player.dir, FOV / 2);
	len = vec2_mag(vec2_sub(dir, tmp));
	step = vec2_mrot(data->player.dir, g_rot90);
	step = vec2_mul(step, len / WIDTH);
	i = 0;
	while (i < WIDTH)
	{
		data->rays[i].pos = &data->player.pos;
		data->rays[i].dir = vec2_norm(dir);
		data->rays[i].idx = i;
		dir = vec2_add(dir, step);
		i++;
	}
}

/// \brief Update the ray directions
/// \param data Pointer to the main data structure
/// \param rot The rotation matrix
/// \return none
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
