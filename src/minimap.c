/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:05:44 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 16:05:44 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.pos.x * 5);
	y = (int)(data->player.pos.y * 5);
	my_mlx_pixel_put(&data->img, x - 1, y - 1, 0x0000FF00);
	my_mlx_pixel_put(&data->img, x - 1, y, 0x0000FF00);
	my_mlx_pixel_put(&data->img, x - 1, y + 1, 0x0000FF00);
	my_mlx_pixel_put(&data->img, x, y - 1, 0x0000FF00);
	my_mlx_pixel_put(&data->img, x, y, 0x0000FF00);
	my_mlx_pixel_put(&data->img, x, y + 1, 0x0000FF00);
	my_mlx_pixel_put(&data->img, x + 1, y - 1, 0x0000FF00);
	my_mlx_pixel_put(&data->img, x + 1, y, 0x0000FF00);
	my_mlx_pixel_put(&data->img, x + 1, y + 1, 0x0000FF00);
}

static void	draw_tile(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = x - 4;
	while (++i < x + 3)
	{
		j = y - 3;
		while (j < y + 3)
			my_mlx_pixel_put(&data->img, i, j++, 0x00FF0000);
	}
}

static void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (data->map.map[i][j].type)
				draw_tile(data, j * 5 + 3, i * 5 + 3);
		}
	}
}

static void	draw_rays(t_data *data)
{
	t_vec2	vec;
	int		x;
	int		y;
	int		i;
	double	j;

	i = 48;
	while (i < WIDTH)
	{
		j = 1;
		vec = vec2_mul(data->rays[i].dir, j);
		vec = vec2_add(data->player.pos, vec);
		while (j < 15 && !is_wall(data->map, vec))
		{
			vec = vec2_mul(data->rays[i].dir, j);
			vec = vec2_add(data->player.pos, vec);
			x = (int)(vec.x * 5);
			y = (int)(vec.y * 5);
			my_mlx_pixel_put(&data->img, x, y, 0x0000FF00);
			j += 0.1;
		}
		i += 12;
	}
}

void	draw_minimap(t_data *data)
{
	draw_rays(data);
	draw_map(data);
	draw_player(data);
}
