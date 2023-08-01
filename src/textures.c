/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:23:25 by treeps            #+#    #+#             */
/*   Updated: 2023/07/27 12:30:44 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// \brief Load a texture from a path to an image
/// \param data Pointer to the main data structure
/// \param texture Pointer to the texture structure
/// \return 1 on success, 0 on failure
int	load_texture(t_data *data, t_texture *texture)
{
	texture->img.img = mlx_xpm_file_to_image(data->mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img.img)
		return (0);
	texture->img.addr = mlx_get_data_addr(texture->img.img, &texture->img.bpp,
			&texture->img.length, &texture->img.endian);
	return (1);
}

/// \brief Draw a texture to the Screen image
/// \param img Pointer to the Screen image
/// \param texture The texture to draw
/// \param x The x position to draw the texture to
/// \param y The y position to draw the texture to
/// \return none
void	draw_texture(t_img *img, t_texture texture, int x, int y)
{
	int	tex_x;
	int	tex_y;
	int	color;

	tex_x = 0;
	while (tex_x < texture.width)
	{
		tex_y = 0;
		while (tex_y < texture.height)
		{
			color = get_pixel_value(&texture.img, tex_x, tex_y);
			my_mlx_pixel_put(img, x + tex_x, y + tex_y, color);
			tex_y++;
		}
		tex_x++;
	}
}

/// \brief returns the type of wall the ray hit
/// \param intersect the intersection of the ray and the wall
/// \return 0 for north wall, 1 for south wall, 2 for west wall, 3 for east wall
int	get_wall_type(t_intersect intersect)
{
	t_vec2	rdir;
	t_vec2	ipos;

	rdir = intersect.ray->dir;
	ipos = intersect.pos;
	return (0);
	if (!(ipos.x - (int)ipos.x) || rdir.y == 0)
	{
		if (rdir.x < 0)
			return (3);
		else
			return (2);
	}
	else if (!(ipos.y - (int)ipos.y) || rdir.x == 0)
	{
		if (rdir.y < 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

/// \brief Draw a column of a wall to the Screen image
/// \param data Pointer to the main data structure
/// \param img Pointer to the Screen image
/// \param tex The texture to draw
/// \param sect The intersection of the ray and the wall
/// \return none
void	draw_column(t_data *data, t_img *img, t_texture tex, t_intersect sect)
{
	double	ratio;
	double	i;
	int		y;
	int		w_height;
	int		tex_col;

	w_height = (int)(2 * HEIGHT / vec2_mag(vec2_sub(sect.pos, *sect.ray->pos)));
	ratio = ((double)tex.height / (double)w_height);
	tex_col = (int)(max(sect.pos.x - (int)sect.pos.x, sect.pos.y - \
				(int)sect.pos.y) * tex.width);
	i = 0;
	y = 0;
	while (y < HEIGHT / 2 - w_height / 2)
		my_mlx_pixel_put(img, sect.ray->idx, y++, data->map.ceiling_color);
	while (i < tex.height)
	{
		my_mlx_pixel_put(img, sect.ray->idx, y++,
			(int)get_pixel_value(&tex.img, tex_col, (int)i));
		i += ratio;
	}
	while (y < HEIGHT)
		my_mlx_pixel_put(img, sect.ray->idx, y++, data->map.floor_color);
}

/// \brief Draw a ray to the Screen image
/// \param data Pointer to the main data structure
/// \param intersect The intersection of the ray and the wall
/// \return none
void	draw_ray(t_data *data, t_intersect intersect)
{
	int			type;
	t_texture	tex[4];

	tex[0] = data->map.texture_no;
	tex[1] = data->map.texture_so;
	tex[2] = data->map.texture_we;
	tex[3] = data->map.texture_ea;
	type = get_wall_type(intersect);
	draw_column(data, &data->img, tex[type], intersect);
}
