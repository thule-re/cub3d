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

void	test_render(t_data *data)
{
	int		x;
	int		y;
	t_vec2	b;

	clear_screen(data);
	draw_box(data);
	draw_grid(data);
	x = (int)(data->player.pos.x * 10) + WIDTH / 2;
	y = (int)(data->player.pos.y * 10) + HEIGHT / 2;
	draw_rect(data, x, y, 6, 0x0000FF00);
	b = vec2_mul(data->player.dir, 2.5);
	b = vec2_add(data->player.pos, b);
	x = (int)(b.x * 10) + WIDTH / 2;
	y = (int)(b.y * 10) + HEIGHT / 2;
	my_mlx_pixel_put(data, x, y, 0x00FF0000);
	draw_rays(data);
}

void	draw_grid(t_data *data)
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
				draw_rect(data, j * 10 + 5 + WIDTH / 2, i * 10 + 5 + HEIGHT / 2, 10, 0x00FF0000);
		}
	}
}

void	draw_box(t_data *data)
{
	int	i;

	i = 10;
	while (i < HEIGHT - 10)
	{
		my_mlx_pixel_put(data, 10, i, 0x00FFFFFF);
		my_mlx_pixel_put(data, WIDTH - 10, i, 0x00FFFFFF);
		i++;
	}
	i = 10;
	while (i < WIDTH - 10)
	{
		my_mlx_pixel_put(data, i, 10, 0x00FFFFFF);
		my_mlx_pixel_put(data, i, HEIGHT - 10, 0x00FFFFFF);
		i++;
	}
}

void	draw_rect(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = x - size / 2;
	while (i < x + size / 2)
	{
		j = y - size / 2;
		while (j < y + size / 2)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}

void	clear_screen(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(data, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}

void	draw_rays(t_data *data)
{
	t_vec2	vec;
	int		x;
	int		y;
	int		i;
	double	j;

	j = 3;
	while (j < 25)
	{
		i = 48;
		while (i < WIDTH)
		{
			vec = vec2_mul(data->rays[i].dir, j);
			vec = vec2_add(data->player.pos, vec);
			x = (int)(vec.x * 10) + WIDTH / 2;
			y = (int)(vec.y * 10) + HEIGHT / 2;
			my_mlx_pixel_put(data, x, y, 0x0000FF00);
			i += 96;
		}
		j += 0.1;
	}
}
