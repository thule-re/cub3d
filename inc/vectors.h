/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:43:35 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 14:15:59 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>

typedef struct s_vec2 {
	double	x;
	double	y;
}				t_vec2;

typedef struct s_mat2 {
	double	m[2][2];
}				t_mat2;

static const t_mat2	g_rot90 = {
	.m = {{0, -1}, \
		{1, 0}}
};

static const t_mat2	g_rot180 = {
	.m = {{-1, 0}, \
		{0, -1}}
};

static const t_mat2	g_rot270 = {
	.m = {{0, 1}, \
		{-1, 0}}
};

static const t_mat2	g_rot3 = {
	.m = {{-0.9899924966, -0.14112000806}, \
		{0.14112000806, -0.9899924966}}
};

static const t_mat2	g_rot357 = {
	.m = {{-0.27516333805, -0.96126169594}, \
		{0.96126169594, -0.27516333805}}
};

t_vec2	vec2_add(t_vec2 a, t_vec2 b);
t_vec2	vec2_sub(t_vec2 a, t_vec2 b);
t_vec2	vec2_mul(t_vec2 a, double b);
t_vec2	vec2_div(t_vec2 a, double b);
double	vec2_dot(t_vec2 a, t_vec2 b);
double	vec2_mag(t_vec2 a);
t_vec2	vec2_norm(t_vec2 a);
t_vec2	vec2_mrot(t_vec2 a, t_mat2 rot);
t_vec2	vec2_rot(t_vec2 a, double angle);


#endif
