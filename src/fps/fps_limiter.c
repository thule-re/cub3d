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

/// \brief this function returns the current time in microseconds
/// \return the current time in microseconds
static unsigned long	get_time_in_us(void)
{
	t_timeval		time;
	unsigned long	time_in_us;

	gettimeofday(&time, 0);
	time_in_us = time.tv_sec * 1000000 + time.tv_usec;
	return (time_in_us);
}

/// \brief this function limits the fps to the value of FPS
/// \return none
void	fps_limiter(void)
{
	static unsigned long	last_time;

	while (get_time_in_us() - last_time < (1000000 / FPS))
		;
	last_time = get_time_in_us();
}
