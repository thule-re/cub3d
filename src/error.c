/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:44:23 by treeps            #+#    #+#             */
/*   Updated: 2023/07/19 16:44:23 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wrong_usage(void)
{
	ft_putstr_fd("Usage: ./cub3D map.cub\n", 2);
	exit(1);
}

void	file_error(char *filename)
{
	ft_putstr_fd("cub3D: ", 2);
	ft_putstr_fd("Could not open file ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	error(t_data *data, char *msg)
{
	ft_putstr_fd("cub3D: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	clean_exit(data);
}
