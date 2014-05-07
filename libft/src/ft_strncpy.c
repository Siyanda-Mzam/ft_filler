/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:44:16 by sconso            #+#    #+#             */
/*   Updated: 2013/11/21 01:51:38 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (src[i])
			dst[i] = src[i];
		else
		{
			while (i < n)
				dst[i++] = 0;
		}
		i++;
	}
	return (dst);
}
