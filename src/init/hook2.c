/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:24:39 by treeps            #+#    #+#             */
/*   Updated: 2023/08/06 13:24:39 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// \brief handle mouse button press
/// \param k keycode
/// \param data
/// \return keycode of the pressed button
int	button_down(int k, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (k == data->mouse.rmb.keycode)
	{
		if (data->mouse.rmb.is_pressed)
		{
			data->mouse.rmb.is_pressed = 0;
			mlx_mouse_show(data->mlx, data->win);
		}
		else
		{
			data->mouse.rmb.is_pressed = 1;
			mlx_mouse_hide(data->mlx, data->win);
			mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
		}
	}
	else if (k == data->mouse.lmb.keycode)
		data->mouse.lmb.is_pressed = 1;
	else if (k == data->mouse.mmb.keycode)
		data->mouse.mmb.is_pressed = 1;
	return (0);
}

/// \brief handle mouse button release
/// \param k keycode
/// \param data
/// \return keycode of the released button
int	button_up(int k, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (k == data->mouse.lmb.keycode)
		data->mouse.lmb.is_pressed = 0;
	if (k == data->mouse.mmb.keycode)
		data->mouse.mmb.is_pressed = 0;
	return (k);
}
