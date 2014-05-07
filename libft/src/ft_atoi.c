/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:34:11 by sconso            #+#    #+#             */
/*   Updated: 2013/11/25 19:24:16 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_tests.h>

int		ft_atoi(const char *str)
{
	int		nb;
	int		isneg;

	isneg = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	nb = 0;
	if (*str == '-')
		isneg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10;
		nb = nb + (*str++ - '0');
	}
	if (isneg == 1)
		nb = -nb;
	return (nb);
}
