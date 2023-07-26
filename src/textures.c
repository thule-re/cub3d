/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:23:25 by treeps            #+#    #+#             */
/*   Updated: 2023/07/24 13:23:25 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
/// \return 0 for south wall, 1 for north wall, 2 for east wall, 3 for west wall
int	get_wall_type(t_intersect intersect)
{
	t_vec2	rdir;
	t_vec2	ipos;

	rdir = intersect.ray->dir;
	ipos = intersect.pos;
	if (rdir.x < 0 && ((ipos.x - (int)ipos.x) == 0 || rdir.y == 0))
		return (2);
	else if (rdir.x > 0 && ((ipos.x - (int)ipos.x) == 0 || rdir.y == 0))
		return (3);
	else if (rdir.y < 0 && ((ipos.y - (int)ipos.y) == 0 || rdir.x == 0))
		return (0);
	else if (rdir.y > 0 && ((ipos.y - (int)ipos.y) == 0 || rdir.x == 0))
		return (1);
	return (0);
}


void	draw_texture_column(t_img *img, t_texture tex, t_intersect sect)
{
	double	ratio;
	double	i;
	int		y;
	int		height;
	int		tex_col;

	height = (int)(0.5 * vec2_mag(vec2_sub(sect.pos, *sect.ray->pos)));
	tex_col = (int)(max(sect.pos.x - (int)sect.pos.x, sect.pos.y -
				(int)sect.pos.y) * tex.width);
	i = 0;
	y = 0;
	ratio = ((double)tex.height / (double)height);
	while (i < tex.height)
	{
		my_mlx_pixel_put(img, sect.ray->idx, y - height / 2 + HEIGHT / 2,
			(int)get_pixel_value(&tex.img, tex_col, (int)i));
		y++;
		i += ratio;
	}
}

void	draw_column(t_data *data, t_intersect intersect)
{
	int			type;
	t_texture	tex[4];

	tex[0] = data->map.texture_no;
	tex[1] = data->map.texture_so;
	tex[2] = data->map.texture_we;
	tex[3] = data->map.texture_ea;
	type = get_wall_type(intersect);
	draw_texture_column(&data->img, tex[type], intersect);
}
