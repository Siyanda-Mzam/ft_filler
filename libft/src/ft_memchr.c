/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:11:57 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:32:42 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char		*strcopy;

	strcopy = (const unsigned char *)str;
	while (n--)
	{
		if (*strcopy == (unsigned char)c)
			return ((void *)strcopy);
		strcopy++;
	}
	return (0);
}
