/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:07:07 by sconso            #+#    #+#             */
/*   Updated: 2013/11/20 11:29:54 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (str2[j] && j < n)
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = 0;
	return (str1);
}
