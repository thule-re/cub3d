/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:46:39 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 13:46:39 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	vec2_mag(t_vec2 a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

t_vec2	vec2_norm(t_vec2 a)
{
	t_vec2	result;
	double	mag;

	mag = vec2_mag(a);
	result.x = a.x / mag;
	result.y = a.y / mag;
	return (result);
}

t_vec2	vec2_mrot(t_vec2 a, t_mat2 rot)
{
	t_vec2	result;

	result.x = a.x * rot.m[0][0] + a.y * rot.m[0][1];
	result.y = a.x * rot.m[1][0] + a.y * rot.m[1][1];
	return (result);
}

t_mat2	mat2_rot(double angle)
{
	t_mat2	result;

	result.m[0][0] = cos(angle);
	result.m[0][1] = -sin(angle);
	result.m[1][0] = sin(angle);
	result.m[1][1] = cos(angle);
	return (result);
}

t_vec2	vec2_rot(t_vec2 a, double angle)
{
	t_vec2	result;
	t_mat2	rot;

	rot = mat2_rot(angle);
	result = vec2_mrot(a, rot);
	return (result);
}
