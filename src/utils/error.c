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

/// \brief print usage message and exits
/// \return none
void	wrong_usage(void)
{
	ft_putstr_fd("Usage: ./cub3D map.cub\n", 2);
	exit(1);
}

/// \brief print error message for file error and exits
/// \param filename name of the file that could not be opened
/// \return none
void	file_error(char *filename, t_data *data)
{
	ft_putstr_fd("cub3D: ", 2);
	ft_putstr_fd("Could not open file ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("\n", 2);
	destroy_hook(data);
}

/// \brief print general error message, frees data and exits
/// \param data pointer to data struct
/// \param msg error message
/// \return none
void	error(t_data *data, char *msg)
{
	ft_putstr_fd("cub3D: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	destroy_hook(data);
}
