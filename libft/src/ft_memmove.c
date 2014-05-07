/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:01:24 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:33:25 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dstcpy;
	const char	*srccpy;

	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	if (dst > src)
	{
		while (n--)
			dstcpy[n] = srccpy[n];
	}
	else
	{
		while (n--)
			*dstcpy++ = *srccpy++;
	}
	return (dst);
}
