/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_limiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 03:10:34 by treeps            #+#    #+#             */
/*   Updated: 2023/08/06 03:10:34 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fps.h"
#include "cub3d.h"

unsigned long	get_time_in_us(void)
{
	t_timeval		time;
	unsigned long	time_in_us;

	gettimeofday(&time, 0);
	time_in_us = time.tv_sec * 1000000 + time.tv_usec;
	return (time_in_us);
}

void	fps_limiter(void)
{
	static unsigned long	last_time;
	unsigned long			current_time;
	unsigned long			time_diff;

	current_time = get_time_in_us();
	time_diff = current_time - last_time;
	while (time_diff < (1000000 / FPS))
		time_diff = get_time_in_us() - last_time;
	last_time = get_time_in_us();
}
