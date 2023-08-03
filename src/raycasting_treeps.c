/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:00:29 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 15:00:29 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vec2	check_x_intersect(t_map map, t_ray ray)
{
	t_vec2		start;
	t_vec2		step;

	step = vec2_div(ray.dir, fabs(ray.dir.x));
	start = vec2_add(*ray.pos, vec2_mul(step, 1 - (fabs(ray.pos->x) - (int)fabs(ray.pos->x))));
	while (!is_wall(map, start))
		start = vec2_add(start, step);
	return (start);
}

static t_vec2	check_y_intersect(t_map map, t_ray ray)
{
	t_vec2	start;
	t_vec2	step;

	step = vec2_div(ray.dir, fabs(ray.dir.y));
	start = vec2_add(*ray.pos, vec2_mul(step, 1 - (fabs(ray.pos->y) - (int)fabs(ray.pos->y))));
	while (!is_wall(map, start))
		start = vec2_add(start, step);
	return (start);
}

static void	cast_ray(t_data *data, t_ray ray)
{
	t_vec2		x_sect;
	t_vec2		y_sect;
	t_intersect	intersect;

	intersect.ray = &ray;
	x_sect = check_x_intersect(data->map, ray);
	y_sect = check_y_intersect(data->map, ray);
	if (vec2_mag(vec2_sub(x_sect, *ray.pos)) < \
		vec2_mag(vec2_sub(y_sect, *ray.pos)))
		intersect.pos = x_sect;
	else
		intersect.pos = y_sect;
	draw_ray(data, intersect);
}

void	raycasting(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
		cast_ray(data, data->rays[i++]);
}
