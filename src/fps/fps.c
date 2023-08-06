/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:56:31 by treeps            #+#    #+#             */
/*   Updated: 2023/07/27 13:56:31 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fps.h"
#include "cub3d.h"

unsigned int	get_time_in_s(void)
{
	t_timeval		time;
	unsigned int	time_in_s;

	gettimeofday(&time, 0);
	time_in_s = time.tv_sec;
	return (time_in_s);
}

void	fps_module(t_data *data)
{
	static char			*fps;
	static int			fps_count;
	static unsigned int	last_time;
	unsigned int		current_time;

	current_time = get_time_in_s();
	if (current_time != last_time)
	{
		last_time = current_time;
		if (fps)
			free(fps);
		fps = ft_itoa(fps_count);
		fps = ft_strjoinf(ft_strdup("FPS: "), fps);
		fps_count = 0;
	}
	else
		fps_count++;
	mlx_string_put(data->mlx, data->win, WIDTH - 50, 10, 0x0000FF00, fps);
	fps_limiter();
}
