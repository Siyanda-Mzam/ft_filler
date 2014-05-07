/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 23:46:40 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:38:44 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_str.h>

char	*ft_strrchr(const char *str, int c)
{
	int		size;

	size = ft_strlen(str);
	while (size >= 0)
	{
		if (str[size] == (char)c)
			return ((char *)&str[size]);
		size--;
	}
	return (0);
}
