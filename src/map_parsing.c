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

static void	player_direction(t_data *data, char c)
{
	if (c == 'S')
		data->player.dir = vec2_mrot(data->player.dir, g_rot180);
	else if (c == 'E')
		data->player.dir = vec2_mrot(data->player.dir, g_rot90);
	else if (c == 'W')
		data->player.dir = vec2_mrot(data->player.dir, g_rot270);
}

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
				data->player.pos.x = j;
				data->player.pos.y = i;
				player_direction(data, content[i][j]);
			}
		}
	}
	if (data->player.pos.x == -1)
		return (0);
	return (1);
}

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
	return (0);
}
