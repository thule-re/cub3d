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

/// \brief this function draws a tile to the minimap
/// \param data data struct
/// \param x x position of the tile
/// \param y y position of the tile
/// \param color color of the tile
/// \return none
void	draw_tile(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = x - 4;
	while (++i < x + 3)
	{
		j = y - 3;
		while (j < y + 3)
			my_mlx_pixel_put(&data->img, i, j++, color);
	}
}

/// \brief this function checks if the given tile is a wall
/// \param map map struct
/// \param pos position of the tile
/// \return 1 if the tile is a wall, 0 if not
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
	if (y - (int)y == 0)
		if (map.map[(int)y - 1][(int)x].type == 1)
			return (1);
	if (x - (int)x == 0)
		if (map.map[(int)y][(int)x - 1].type == 1)
			return (1);
	return (0);
}
