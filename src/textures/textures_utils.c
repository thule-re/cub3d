/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:06:51 by treeps            #+#    #+#             */
/*   Updated: 2023/08/04 17:06:51 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// \brief Load a texture from a path to an image
/// \param data Pointer to the main data structure
/// \param texture Pointer to the texture structure
/// \return 1 on success, 0 on failure
static int	load_texture(t_data *data, t_texture *texture)
{
	texture->img.img = mlx_xpm_file_to_image(data->mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img.img)
		return (0);
	texture->img.addr = mlx_get_data_addr(texture->img.img, &texture->img.bpp,
			&texture->img.length, &texture->img.endian);
	return (1);
}

/// \brief loads the textures from the path in the config file to an image
/// \param data Pointer to the main data structure
/// \return 1 on success, 0 on failure
int	load_textures(t_data *data)
{
	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;

	no = &data->map.texture_no;
	so = &data->map.texture_so;
	we = &data->map.texture_we;
	ea = &data->map.texture_ea;
	load_texture(data, no);
	load_texture(data, so);
	load_texture(data, we);
	load_texture(data, ea);
	if (!no->img.img || !so->img.img || !we->img.img || !ea->img.img)
		return (0);
	return (1);
}
