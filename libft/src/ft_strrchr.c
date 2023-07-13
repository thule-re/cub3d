/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:40:00 by treeps            #+#    #+#             */
/*   Updated: 2023/05/17 12:11:10 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	l;

	l = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == l)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
