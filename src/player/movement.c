/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:20:53 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 14:20:53 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// \brief Handle keys that are pressed
/// \param data Pointer to the main data structure
/// \return none
void	handle_keys(t_data *data)
{
	if (data->keys.forward.is_pressed)
		move_forward(data);
	if (data->keys.backward.is_pressed)
		move_backward(data);
	if (data->keys.left.is_pressed)
		move_left(data);
	if (data->keys.right.is_pressed)
		move_right(data);
	if (data->keys.turn_left.is_pressed)
		turn_left(data);
	if (data->keys.turn_right.is_pressed)
		turn_right(data);
	if (data->mouse.rmb.is_pressed)
		mouse_turn(data);
}

/// \brief Move the player forward
/// \param data Pointer to the main data structure
/// \return none
void	move_forward(t_data *data)
{
	t_vec2	new_pos;
	t_vec2	dir;
	t_vec2	tmp_x;
	t_vec2	tmp_y;

	dir = vec2_mul(data->player.dir, data->player.move_speed);
	new_pos = vec2_add(data->player.pos, dir);
	if (!is_in_hitbox(data->map, new_pos))
		data->player.pos = new_pos;
	else
	{
		tmp_x.x = new_pos.x;
		tmp_x.y = data->player.pos.y;
		tmp_y.y = new_pos.y;
		tmp_y.x = data->player.pos.x;
		if (!is_in_hitbox(data->map, tmp_x))
			data->player.pos = tmp_x;
		else if (!is_in_hitbox(data->map, tmp_y))
			data->player.pos = tmp_y;
	}
}

/// \brief Move the player backward
/// \param data Pointer to the main data structure
/// \return none
void	move_backward(t_data *data)
{
	t_vec2	new_pos;
	t_vec2	dir;
	t_vec2	tmp_x;
	t_vec2	tmp_y;

	dir = vec2_mul(data->player.dir, data->player.move_speed);
	new_pos = vec2_sub(data->player.pos, dir);
	if (!is_in_hitbox(data->map, new_pos))
		data->player.pos = new_pos;
	else
	{
		tmp_x.x = new_pos.x;
		tmp_x.y = data->player.pos.y;
		tmp_y.y = new_pos.y;
		tmp_y.x = data->player.pos.x;
		if (!is_in_hitbox(data->map, tmp_x))
			data->player.pos = tmp_x;
		else if (!is_in_hitbox(data->map, tmp_y))
			data->player.pos = tmp_y;
	}
}

/// \brief Move the player left
/// \param data Pointer to the main data structure
/// \return none
void	move_left(t_data *data)
{
	t_vec2	new_pos;
	t_vec2	dir;
	t_vec2	tmp_x;
	t_vec2	tmp_y;

	dir = vec2_mrot(data->player.dir, g_rot90);
	dir = vec2_mul(dir, data->player.move_speed);
	new_pos = vec2_sub(data->player.pos, dir);
	if (!is_in_hitbox(data->map, new_pos))
		data->player.pos = new_pos;
	else
	{
		tmp_x.x = new_pos.x;
		tmp_x.y = data->player.pos.y;
		tmp_y.y = new_pos.y;
		tmp_y.x = data->player.pos.x;
		if (!is_in_hitbox(data->map, tmp_x))
			data->player.pos = tmp_x;
		else if (!is_in_hitbox(data->map, tmp_y))
			data->player.pos = tmp_y;
	}
}

/// \brief Move the player right
/// \param data Pointer to the main data structure
/// \return none
void	move_right(t_data *data)
{
	t_vec2	new_pos;
	t_vec2	dir;
	t_vec2	tmp_x;
	t_vec2	tmp_y;

	dir = vec2_mrot(data->player.dir, g_rot270);
	dir = vec2_mul(dir, data->player.move_speed);
	new_pos = vec2_sub(data->player.pos, dir);
	if (!is_in_hitbox(data->map, new_pos))
		data->player.pos = new_pos;
	else
	{
		tmp_x.x = new_pos.x;
		tmp_x.y = data->player.pos.y;
		tmp_y.y = new_pos.y;
		tmp_y.x = data->player.pos.x;
		if (!is_in_hitbox(data->map, tmp_x))
			data->player.pos = tmp_x;
		else if (!is_in_hitbox(data->map, tmp_y))
			data->player.pos = tmp_y;
	}
}
