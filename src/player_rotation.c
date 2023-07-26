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

/// \brief Turn the player left
/// \param data Pointer to the main data structure
/// \return none
void	turn_left(t_data *data)
{
	data->player.dir = vec2_mrot(data->player.dir, data->player.cclockwise_rot);
	data->player.dir = vec2_norm(data->player.dir);
	update_ray_directions(data, data->player.cclockwise_rot);
}

/// \brief Turn the player right
/// \param data Pointer to the main data structure
/// \return none
void	turn_right(t_data *data)
{
	data->player.dir = vec2_mrot(data->player.dir, data->player.clockwise_rot);
	data->player.dir = vec2_norm(data->player.dir);
	update_ray_directions(data, data->player.clockwise_rot);
}
