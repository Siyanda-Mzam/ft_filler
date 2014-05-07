/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:53:40 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:37:31 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_str.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		size;
	int		i;

	if (s == 0 || f == 0)
		return (0);
	size = ft_strlen(s);
	i = -1;
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (str == 0)
		return (0);
	while (++i < size)
		str[i] = f(i, s[i]);
	str[i] = 0;
	return (str);
}
