/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:20:45 by treeps            #+#    #+#             */
/*   Updated: 2023/05/17 12:15:28 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*cpy;

	if (!src)
		return (NULL);
	cpy = (char *)ft_calloc(n, sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < n - 1)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
