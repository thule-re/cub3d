/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:57:14 by treeps            #+#    #+#             */
/*   Updated: 2023/07/19 12:57:14 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

/// \brief creates a clockwise rotation matrix for a given angle
/// \param angle angle in degrees
/// \return rotation matrix
t_mat2	rot_matrixc(double angle)
{
	t_mat2	matrix;
	double	radians;
	double	cos_theta;
	double	sin_theta;

	radians = angle * M_PI / 180.0;
	cos_theta = cos(radians);
	sin_theta = sin(radians);
	matrix.m[0][0] = cos_theta;
	matrix.m[0][1] = -sin_theta;
	matrix.m[1][0] = sin_theta;
	matrix.m[1][1] = cos_theta;
	return (matrix);
}

/// \brief creates a counter clockwise rotation matrix for a given angle
/// \param angle angle in degrees
/// \return rotation matrix
t_mat2	rot_matrixcc(double angle)
{
	t_mat2	matrix;
	double	radians;
	double	cos_theta;
	double	sin_theta;

	radians = angle * M_PI / 180.0;
	cos_theta = cos(radians);
	sin_theta = sin(radians);
	matrix.m[0][0] = cos_theta;
	matrix.m[0][1] = sin_theta;
	matrix.m[1][0] = -sin_theta;
	matrix.m[1][1] = cos_theta;
	return (matrix);
}
