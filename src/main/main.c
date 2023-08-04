/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:53:27 by treeps            #+#    #+#             */
/*   Updated: 2023/07/13 11:53:27 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// \brief main function of the program
/// \param argc argument count
/// \param argv argument values
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		wrong_usage();
	init_data(&data, argv[1]);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}
