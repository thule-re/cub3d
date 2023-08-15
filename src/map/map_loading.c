/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:27:46 by treeps            #+#    #+#             */
/*   Updated: 2023/07/21 15:27:46 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// \brief gather information about the map like width and height
/// \param data Pointer to the main data structure
/// \param map The map as a string array
/// \return 1 on success, 0 on failure
static int	map_telemetry(t_data *data, char **map)
{
	int	i;
	int	lines;
	int	longest_line;

	i = -1;
	lines = 0;
	longest_line = 0;
	while (map[++i])
	{
		if (*map[i] != '1' && *map[i] != ' ')
			return (0);
		if ((int)ft_strlen(map[i]) > longest_line)
			longest_line = (int)ft_strlen(map[i]);
		lines++;
	}
	data->map.height = lines;
	data->map.width = longest_line;
	return (1);
}

/// \brief parses the player direction from the map
/// \param data Pointer to the main data structure
/// \param c The character representing the player direction
/// \return none
static void	player_direction(t_data *data, char c)
{
	if (c == 'S')
		data->player.dir = vec2_mrot(data->player.dir, g_rot180);
	else if (c == 'E')
		data->player.dir = vec2_mrot(data->player.dir, g_rot90);
	else if (c == 'W')
		data->player.dir = vec2_mrot(data->player.dir, g_rot270);
}

/// \brief parses the player position from the map
/// \param data Pointer to the main data structure
/// \param content The map as a string array
/// \return 1 on success, 0 on failure
static int	player_position(t_data *data, char **content)
{
	int	i;
	int	j;

	data->player.pos.x = -1;
	i = -1;
	while (content[++i])
	{
		j = -1;
		while (content[i][++j])
		{
			if (ft_strchr("NSEW", content[i][j]))
			{
				if (data->player.pos.x != -1)
					return (0);
				data->player.pos.x = j + 0.5;
				data->player.pos.y = i + 0.5;
				player_direction(data, content[i][j]);
			}
		}
	}
	if (data->player.pos.x == -1)
		return (0);
	return (1);
}

/// \brief parses the map from the map string array to the map structure
/// \param data Pointer to the main data structure
/// \param content The map as a string array
/// \return error code on failure, 0 on success
int	parse_map(t_data *data, char **content)
{
	int	i;

	if (!map_telemetry(data, content))
		return (1);
	if (!player_position(data, content))
		return (2);
	if (!check_valid(content))
		return (3);
	i = -1;
	data->map.map = ft_calloc(data->map.height + 1, sizeof(t_tile *));
	while (++i < data->map.height)
		data->map.map[i] = ft_calloc(data->map.width + 1, sizeof(t_tile));
	fill_map(data, content);
	if (!load_textures(data))
		return (4);
	return (0);
}

/// \brief Fills the map with the information from the config file
/// \param data Pointer to the main data structure
/// \param map The map as a string array
/// \return none
void	fill_map(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
			data->map.map[i][j].type = 0;
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				data->map.map[i][j].type = 1;
		}
	}
}
