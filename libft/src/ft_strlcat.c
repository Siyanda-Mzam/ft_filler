/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:37:06 by sconso            #+#    #+#             */
/*   Updated: 2013/11/27 18:00:09 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i < size - 1)
	{
		while (i < size - 1 && *src)
		{
			dst[i] = *src++;
			i++;
		}
		dst[i] = 0;
	}
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}
