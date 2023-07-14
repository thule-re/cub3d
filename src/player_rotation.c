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
	data->player.dir = vec2_mrot(data->player.dir, g_rot3);
	data->player.dir = vec2_norm(data->player.dir);
	data->player.update_dir = 1;
}

void	turn_right(t_data *data)
{
	data->player.dir = vec2_mrot(data->player.dir, g_rot357);
	data->player.dir = vec2_norm(data->player.dir);
	data->player.update_dir = 1;
}
