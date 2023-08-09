/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:56:22 by treeps            #+#    #+#             */
/*   Updated: 2023/07/27 13:56:22 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPS_H
# define FPS_H

# include <sys/time.h>
# include "cub3d.h"

typedef struct s_data	t_data;
typedef struct timeval	t_timeval;

void	fps_limiter(void);
void	fps_module(t_data *data);

#endif
