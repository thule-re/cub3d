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
/// \param data Pointer to the main data structure
/// \param str String to parse
/// \return The color as an int
static int	parse_color(t_data *data, char *str)
{
	char	**rgb;
	int		color;

	color = 0;
	str = trim(str, ' ');
	rgb = ft_split(str, ',');
	free(str);
	if (rgb[0] && rgb[1] && rgb[2] && !rgb[3])
	{
		color = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
		free_split(rgb);
	}
	else
	{
		free_split(rgb);
		error(data, "Invalid color");
	}
	return (color);
}

/// \brief Read the config file and return it as a string array
/// \param filename Path to the config file
/// \return The config file as a string array
static char	**read_config(char *filename)
{
	int		fd;
	char	buf[2];
	char	*tmp;
	char	*tmp1;
	char	**content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		file_error(filename);
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
		if (ft_strncmp(content[i], "NO", 2) == 0)
			data->map.texture_no.path = trim(&content[i][2], ' ');
		else if (ft_strncmp(content[i], "SO", 2) == 0)
			data->map.texture_so.path = trim(&content[i][2], ' ');
		else if (ft_strncmp(content[i], "WE", 2) == 0)
			data->map.texture_we.path = trim(&content[i][2], ' ');
		else if (ft_strncmp(content[i], "EA", 2) == 0)
			data->map.texture_ea.path = trim(&content[i][2], ' ');
		else if (ft_strncmp(content[i], "C", 1) == 0)
			data->map.ceiling_color = parse_color(data, &content[i][1]);
		else if (ft_strncmp(content[i], "F", 1) == 0)
			data->map.floor_color = parse_color(data, &content[i][1]);
		else if (content[i][0] == ' ' || content[i][0] == '1' ||
			content[i][0] == '0')
			break ;
	}
	return (i);
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

	data->map.texture_no.path = 0;
	data->map.texture_so.path = 0;
	data->map.texture_we.path = 0;
	data->map.texture_ea.path = 0;
	data->map.ceiling_color = 0;
	data->map.floor_color = 0;
	content = read_config(filename);
	i = parse_config(data, content);
	if (content[i] == NULL)
		error(data, "No map found");
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
