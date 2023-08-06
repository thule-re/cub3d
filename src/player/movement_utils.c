/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 02:57:25 by treeps            #+#    #+#             */
/*   Updated: 2023/08/06 02:57:25 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_hitbox(t_map map, t_vec2 pos)
{
	t_vec2	north_box;
	t_vec2	south_box;
	t_vec2	east_box;
	t_vec2	west_box;

	north_box = (t_vec2){pos.x, pos.y - 0.25};
	south_box = (t_vec2){pos.x, pos.y + 0.25};
	east_box = (t_vec2){pos.x + 0.25, pos.y};
	west_box = (t_vec2){pos.x - 0.25, pos.y};
	if (is_wall(map, pos))
		return (1);
	if (is_wall(map, north_box))
		return (1);
	if (is_wall(map, south_box))
		return (1);
	if (is_wall(map, east_box))
		return (1);
	if (is_wall(map, west_box))
		return (1);
	return (0);
}
