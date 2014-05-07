/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 00:28:10 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:38:31 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		i;
	size_t		ii;
	int			j;

	i = 0;
	ii = 0;
	j = 0;
	if (*str2 == 0)
		return ((char *)str1);
	while (str1[i] != '\0' && i < n)
	{
		while (str1[ii] == str2[j] && ii < n)
		{
			j++;
			ii++;
			if (str2[j] == '\0')
				return ((char *)&str1[ii] - j);
		}
		j = 0;
		ii = ++i;
	}
	return (0);
}
