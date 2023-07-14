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
	int	x;
	int	y;

	clear_screen(data);
	draw_box(data);
	x = data->player.pos.x + WIDTH / 2;
	y = data->player.pos.y + HEIGHT / 2;
	draw_player(data, x, y);
	draw_line(data->player.pos, vec2_mul(vec2_add(data->player.pos, data->player.dir), 5.0), data);
}

void	draw_box(t_data *data)
{
	int	i;
	int	j;

	j = 10;
	while (j < HEIGHT - 10)
	{
		my_mlx_pixel_put(data, 10, j, 0x00FFFFFF);
		j++;
	}
	j = 10;
	while (j < HEIGHT - 10)
	{
		my_mlx_pixel_put(data, WIDTH - 10, j, 0x00FFFFFF);
		j++;
	}
	i = 10;
	while (i < WIDTH - 10)
	{
		my_mlx_pixel_put(data, i, 10, 0x00FFFFFF);
		i++;
	}
	i = 10;
	while (i < WIDTH - 10)
	{
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

void	draw_line(t_vec2 a, t_vec2 b, t_data *data)
{

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
