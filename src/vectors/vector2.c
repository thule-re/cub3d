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

/// \brief calculates the magnitude of a vector
/// \param a vector
/// \return magnitude of the vector
double	vec2_mag(t_vec2 a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

/// \brief normalizes a vector
/// \param a vector
/// \return normalized vector
t_vec2	vec2_norm(t_vec2 a)
{
	t_vec2	result;
	double	mag;

	mag = vec2_mag(a);
	result.x = a.x / mag;
	result.y = a.y / mag;
	return (result);
}

/// \brief multiplies a vector with a matrix
/// \param a vector
/// \param rot matrix
/// \return result of the multiplication
t_vec2	vec2_mrot(t_vec2 a, t_mat2 rot)
{
	t_vec2	result;

	result.x = a.x * rot.m[0][0] + a.y * rot.m[0][1];
	result.y = a.x * rot.m[1][0] + a.y * rot.m[1][1];
	return (result);
}

/// \brief rotates a vector clockwise
/// \param vec vector
/// \param angle angle in degrees
/// \return rotated vector
t_vec2	vec2_rot_clockwise(t_vec2 vec, double angle)
{
	double	radians;
	t_mat2	matrix;
	t_vec2	result;
	double	cos_theta;
	double	sin_theta;

	radians = angle * M_PI / 180.0;
	cos_theta = cos(radians);
	sin_theta = sin(radians);
	matrix.m[0][0] = cos_theta;
	matrix.m[0][1] = -sin_theta;
	matrix.m[1][0] = sin_theta;
	matrix.m[1][1] = cos_theta;
	result = vec2_mrot(vec, matrix);
	return (result);
}

/// \brief rotates a vector counter clockwise
/// \param vec vector
/// \param angle angle in degrees
/// \return rotated vector
t_vec2	vec2_rot_counter_clockwise(t_vec2 vec, double angle)
{
	double	radians;
	t_mat2	matrix;
	t_vec2	result;
	double	cos_theta;
	double	sin_theta;

	radians = angle * M_PI / 180.0;
	cos_theta = cos(radians);
	sin_theta = sin(radians);
	matrix.m[0][0] = cos_theta;
	matrix.m[0][1] = sin_theta;
	matrix.m[1][0] = -sin_theta;
	matrix.m[1][1] = cos_theta;
	result = vec2_mrot(vec, matrix);
	return (result);
}
