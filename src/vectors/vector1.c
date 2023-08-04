/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:43:24 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 13:43:24 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

/// \brief adds two vectors
/// \param a first vector
/// \param b second vector
/// \return result of the addition
t_vec2	vec2_add(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

/// \brief subtracts two vectors
/// \param a first vector
/// \param b second vector
/// \return result of the subtraction
t_vec2	vec2_sub(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

/// \brief multiplies a vector with a scalar
/// \param a vector
/// \param b scalar
/// \return result of the multiplication
t_vec2	vec2_mul(t_vec2 a, double b)
{
	t_vec2	result;

	result.x = a.x * b;
	result.y = a.y * b;
	return (result);
}

/// \brief divides a vector by a scalar
/// \param a vector
/// \param b scalar
/// \return result of the division
t_vec2	vec2_div(t_vec2 a, double b)
{
	t_vec2	result;

	result.x = a.x / b;
	result.y = a.y / b;
	return (result);
}

/// \brief calculates the dot product of two vectors
/// \param a first vector
/// \param b second vector
/// \return result of the dot product
double	vec2_dot(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}
