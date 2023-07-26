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

/// \brief free all map data
/// \param data
/// \return none
void	free_map(t_data *data)
{
	free(data->map.texture_no.path);
	free(data->map.texture_so.path);
	free(data->map.texture_we.path);
	free(data->map.texture_ea.path);
	if (data->map.texture_no.img.img)
		mlx_destroy_image(data->mlx, data->map.texture_no.img.img);
	if (data->map.texture_so.img.img)
		mlx_destroy_image(data->mlx, data->map.texture_so.img.img);
	if (data->map.texture_we.img.img)
		mlx_destroy_image(data->mlx, data->map.texture_we.img.img);
	if (data->map.texture_ea.img.img)
		mlx_destroy_image(data->mlx, data->map.texture_ea.img.img);
}
