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

/// \brief Check if the ray intersects with a vertical wall
/// \param map The map
/// \param ray The ray to check
/// \return The intersection point
static t_vec2	check_x_intersect(t_map map, t_ray ray)
{
	t_vec2		start;
	t_vec2		step;

	step = vec2_div(ray.dir, fabs(ray.dir.x));
	if (ray.dir.x < 0)
		start = vec2_add(*ray.pos, vec2_mul(step, (fabs(ray.pos->x) - \
		(int)fabs(ray.pos->x))));
	else
		start = vec2_add(*ray.pos, vec2_mul(step, 1 - (fabs(ray.pos->x) - \
		(int)fabs(ray.pos->x))));
	while (!is_wall(map, start))
		start = vec2_add(start, step);
	return (start);
}

/// \brief Check if the ray intersects with a horizontal wall
/// \param map The map
/// \param ray The ray to check
/// \return The intersection point
static t_vec2	check_y_intersect(t_map map, t_ray ray)
{
	t_vec2	start;
	t_vec2	step;

	step = vec2_div(ray.dir, fabs(ray.dir.y));
	if (ray.dir.y < 0)
		start = vec2_add(*ray.pos, vec2_mul(step, (fabs(ray.pos->y) - \
		(int)fabs(ray.pos->y))));
	else
		start = vec2_add(*ray.pos, vec2_mul(step, 1 - (fabs(ray.pos->y) - \
		(int)fabs(ray.pos->y))));
	while (!is_wall(map, start))
		start = vec2_add(start, step);
	return (start);
}

/// \brief Cast a ray and draw it
/// \param data Pointer to the main data structure
/// \param ray The ray to cast
/// \return none
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

/// \brief Cast rays for column of pixels
/// \param data Pointer to the main data structure
/// \return none
void	raycasting(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
		cast_ray(data, data->rays[i++]);
}
