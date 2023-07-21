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

int	check_surrounding(char **map, int i, int j)
{
	if (i == 0 || j == 0)
		return (0);
	if (!map[i][j + 1] || !map[i + 1])
		return (0);
	if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
		return (0);
	if (map[i - 1][j + 1] == ' ' || map[i - 1][j - 1] == ' ')
		return (0);
	if (map[i + 1][j + 1] == ' ' || map[i + 1][j - 1] == ' ')
		return (0);
	if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
		return (0);
	return (1);
}

int	check_valid(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == '0')
				if (!check_surrounding(map, i, j))
					return (0);
	}
	return (1);
}
