/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:28:39 by treeps            #+#    #+#             */
/*   Updated: 2023/07/19 16:28:39 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// \brief Check if a given character is valid
/// \param c The character to check
/// \return 1 if the character is valid, 0 otherwise
static int	valid_char(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || \
	c == 'E' || c == 'W')
		return (1);
	return (0);
}

/// \brief Check if a given cell is surrounded by walls, empty or invalid cells
/// \param map The map as a string array
/// \param x The x coordinate of the cell
/// \param y The y coordinate of the cell
/// \return 1 if the cell is surrounded by walls or empty cells, 0 otherwise
int	check_surrounding(char **map, int x, int y)
{
	if (y == 0 || x == 0)
		return (0);
	if (!map[y][x + 1] || !map[y + 1])
		return (0);
	if (map[y - 1][x + 1] < '0' || map[y - 1][x] < '0' || \
	map[y - 1][x - 1] < '0')
		return (0);
	if (map[y][x + 1] < '0' || map[y][x - 1] < '0')
		return (0);
	if (map[y + 1][x + 1] < '0' || map[y + 1][x] < '0' || \
	map[y + 1][x - 1] < '0')
		return (0);
	return (1);
}

/// \brief Check if the map is valid
/// \param map The map as a string array
/// \return 1 if the map is valid, 0 otherwise
int	check_valid(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!valid_char(map[i][j]))
				return (0);
			if (ft_strchr("0NSEW", map[i][j]))
				if (!check_surrounding(map, j, i))
					return (0);
		}
	}
	return (1);
}
