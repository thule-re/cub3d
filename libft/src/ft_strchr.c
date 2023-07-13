/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:41 by treeps            #+#    #+#             */
/*   Updated: 2023/05/17 12:11:10 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	l;

	l = (char)c;
	i = 0;
	len = ft_strlen(s);
	while (i < len + 1)
	{
		if (s[i] == l)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
