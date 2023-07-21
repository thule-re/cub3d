/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:24:24 by treeps            #+#    #+#             */
/*   Updated: 2023/07/21 13:24:24 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_map map)
{
	free(map.path_no);
	free(map.path_so);
	free(map.path_we);
	free(map.path_ea);
}

void	clean_exit(t_data *data)
{
	free_map(data->map);
	if (data->mlx)
		destroy_hook(data);
	exit(1);
}
