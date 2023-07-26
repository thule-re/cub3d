/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:45:22 by treeps            #+#    #+#             */
/*   Updated: 2023/07/13 12:45:22 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_value(t_img *img, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return (-1);
	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	return (*(int *)dst);
}

char	*trim(char *str, char c)
{
	int		i;
	int		j;
	int		count;
	char	*new;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == c)
			count++;
	i = ft_strlen(str) - count;
	new = ft_calloc(i + 1, sizeof(char));
	i = -1;
	j = -1;
	while (str[++i])
		if (str[i] != c)
			new[++j] = str[i];
	return (new);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
