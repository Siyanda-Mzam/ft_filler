/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:19:50 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:31:04 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		ft_addnbr(int n, char *str)
{
	if (n != 0)
	{
		if (n / 10 != 0)
			ft_addnbr(n / 10, str - 1);
		n %= 10;
		if (n < 0)
			n = -n;
		*str = n + '0';
	}
	else
		*str = '0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		ncpy;
	int		size;

	ncpy = n;
	size = 1;
	while (ncpy >= 10 || ncpy <= -10)
	{
		size++;
		ncpy /= 10;
	}
	if (n < 0)
		size++;
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (n < 0)
		str[0] = '-';
	ft_addnbr(n, &str[size - 1]);
	str[size] = 0;
	return (str);
}
