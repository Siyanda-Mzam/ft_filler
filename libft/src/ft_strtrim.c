/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:01:51 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:39:30 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_str.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		l;
	int		i;
	int		j;

	if (s == 0)
		return (0);
	l = ft_strlen(s);
	str = (char *)malloc((l + 1) * sizeof(*str));
	i = 0;
	j = 0;
	while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t' || s[l] == 0)
	{
		str[l] = 0;
		l--;
	}
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (i <= l)
		str[j++] = s[i++];
	return (str);
}
