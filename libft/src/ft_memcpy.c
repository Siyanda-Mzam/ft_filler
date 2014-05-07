/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:06:42 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:33:11 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dstcpy;
	const char		*srccpy;

	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	while (n--)
		*dstcpy++ = *srccpy++;
	return (dst);
}
