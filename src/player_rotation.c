/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:27:38 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 14:27:38 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_data *data)
{
	data->player.dir = vec2_mrot(data->player.dir, g_counter_clockwise_matrix);
	data->player.dir = vec2_norm(data->player.dir);
	update_ray_directions(data, g_counter_clockwise_matrix);
}

void	turn_right(t_data *data)
{
	data->player.dir = vec2_mrot(data->player.dir, g_clockwise_matrix);
	data->player.dir = vec2_norm(data->player.dir);
	update_ray_directions(data, g_clockwise_matrix);
}
