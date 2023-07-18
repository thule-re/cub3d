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
	x = (int)data->player.pos.x + WIDTH / 2;
	y = (int)data->player.pos.y + HEIGHT / 2;
	draw_player(data, x, y);
	b = vec2_mul(data->player.dir, 25.0);
	b = vec2_add(data->player.pos, b);
	x = (int)b.x + WIDTH / 2;
	y = (int)b.y + HEIGHT / 2;
	my_mlx_pixel_put(data, x, y, 0x00FF0000);
	draw_rays(data);
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

void	draw_player(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = x - 3;
	while (i < x + 3)
	{
		j = y - 3;
		while (j < y + 3)
		{
			my_mlx_pixel_put(data, i, j, 0x00FF0000);
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

	i = 0;

	while (i < WIDTH)
	{
		vec = vec2_mul(data->rays[i].dir, 30.0);
		vec = vec2_add(data->player.pos, vec);
		x = vec.x + WIDTH / 2;
		y = vec.y + HEIGHT / 2;
		my_mlx_pixel_put(data, x, y, 0x0000FF00);
		i++;
	}

}
