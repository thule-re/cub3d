/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:49:16 by treeps            #+#    #+#             */
/*   Updated: 2023/07/14 15:49:16 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// \brief Parse a color from a string in the format "R,G,B"
/// \param str String to parse
/// \return The color as an int
static int	parse_color(char *str)
{
	char	**rgb;
	int		i_rgb[3];
	int		color;

	color = 0;
	str = trim(str, ' ');
	rgb = ft_split(str, ',');
	free(str);
	if (ft_isdigits(rgb[0]) && ft_isdigits(rgb[1]) && ft_isdigits(rgb[2]) \
	&& !rgb[3])
	{
		i_rgb[0] = ft_atoi(rgb[0]);
		i_rgb[1] = ft_atoi(rgb[1]);
		i_rgb[2] = ft_atoi(rgb[2]);
	}
	else
		color = -1;
	free_split(rgb);
	if (color == -1 || i_rgb[0] > 255 || i_rgb[1] > 255 || i_rgb[2] > 255)
		return (-1);
	return (i_rgb[0] << 16 | i_rgb[1] << 8 | i_rgb[2]);
}

/// \brief Read the config file and return it as a string array
/// \param filename Path to the config file
/// \return The config file as a string array
static char	**read_config(char *filename, t_data *data)
{
	int		fd;
	char	buf[2];
	char	*tmp;
	char	*tmp1;
	char	**content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		file_error(filename, data);
	tmp = ft_calloc(1, sizeof(char));
	while (read(fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		tmp1 = tmp;
		tmp = ft_strjoin(tmp1, buf);
		free(tmp1);
	}
	close(fd);
	content = ft_split(tmp, '\n');
	free(tmp);
	return (content);
}

/// \brief Parse the config file and read the identifiers
/// \param data Pointer to the main data structure
/// \param content The config file as a string array
/// \return The index of the first line of the map
static int	parse_config(t_data *data, char **content)
{
	int		i;

	i = -1;
	while (content[++i])
	{
		if (ft_strncmp(content[i], "#", 1) == 0)
			continue ;
		else if (!ft_strncmp(content[i], "NO", 2) && !data->map.texture_no.path)
			data->map.texture_no.path = trim(&content[i][2], ' ');
		else if (!ft_strncmp(content[i], "SO", 2) && !data->map.texture_so.path)
			data->map.texture_so.path = trim(&content[i][2], ' ');
		else if (!ft_strncmp(content[i], "WE", 2) && !data->map.texture_we.path)
			data->map.texture_we.path = trim(&content[i][2], ' ');
		else if (!ft_strncmp(content[i], "EA", 2) && !data->map.texture_ea.path)
			data->map.texture_ea.path = trim(&content[i][2], ' ');
		else if (!ft_strncmp(content[i], "C", 1) && data->map.ceiling == -1)
			data->map.ceiling = parse_color(&content[i][1]);
		else if (!ft_strncmp(content[i], "F", 1) && data->map.floor == -1)
			data->map.floor = parse_color(&content[i][1]);
		else if (content[i][0] == ' ' || content[i][0] == '1' ||
			content[i][0] == '0')
			break ;
	}
	return (i);
}

static void	init_values(t_map *map)
{
	map->texture_no.path = NULL;
	map->texture_so.path = NULL;
	map->texture_we.path = NULL;
	map->texture_ea.path = NULL;
	map->ceiling = -1;
	map->floor = -1;
	map->map = NULL;
}

/// \brief gets all the information from the config file
/// \param data Pointer to the main data structure
/// \param filename Path to the config file
/// \return none
void	init_map(t_data *data, char *filename)
{
	char	**content;
	int		i;
	int		code;

	init_values(&data->map);
	content = read_config(filename, data);
	i = parse_config(data, content);
	if (content[i] == NULL)
		error(data, "No map found");
	if (data->map.floor == -1 || data->map.ceiling == -1)
	{
		free_split(content);
		error(data, "Invalid Color");
	}
	code = parse_map(data, &content[i]);
	free_split(content);
	if (code != 0)
	{
		if (code == 1 || code == 3)
			error(data, "Invalid map");
		else if (code == 2)
			error(data, "Invalid player position");
		else if (code == 4)
			error(data, "Unable to load texture");
	}
}
