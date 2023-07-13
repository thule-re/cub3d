/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:14:01 by treeps            #+#    #+#             */
/*   Updated: 2023/07/13 13:22:46 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int k, t_data *data)
{
	ft_printf("%d\n", k);
	if (k == KEY_ESCAPE)
		destroy_hook(data);
	return (k);
}

int	destroy_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
}

int	loop_hook(t_data *data)
{
	my_mlx_pixel_put(data, 10, 10, 0xFF0000);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
