/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:59:10 by treeps            #+#    #+#             */
/*   Updated: 2023/08/01 11:59:10 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_map map, t_vec2 pos)
{
	double	x;
	double	y;

	x = pos.x;
	y = pos.y;
	if (x < 1.0 || x >= map.width - 1 || y < 1.0 || y >= map.height - 1)
		return (1);
	if (map.map[(int)y][(int)x].type == 1)
		return (1);
	return (0);
}