/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:24:24 by treeps            #+#    #+#             */
/*   Updated: 2023/07/21 13:24:24 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_tiles(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
		free (map.map[i++]);
	free(map.map);
}

/// \brief free all map data
/// \param data
/// \return none
void	free_map(t_data *data)
{
	if (data->map.texture_no.path)
		free(data->map.texture_no.path);
	if (data->map.texture_so.path)
		free(data->map.texture_so.path);
	if (data->map.texture_we.path)
		free(data->map.texture_we.path);
	if (data->map.texture_ea.path)
		free(data->map.texture_ea.path);
	if (data->map.texture_no.img.img)
		mlx_destroy_image(data->mlx, data->map.texture_no.img.img);
	if (data->map.texture_so.img.img)
		mlx_destroy_image(data->mlx, data->map.texture_so.img.img);
	if (data->map.texture_we.img.img)
		mlx_destroy_image(data->mlx, data->map.texture_we.img.img);
	if (data->map.texture_ea.img.img)
		mlx_destroy_image(data->mlx, data->map.texture_ea.img.img);
	if (data->map.map)
		free_tiles(data->map);
}
