/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createdlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:28:05 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:29:56 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_index			*ft_createdlist(void)
{
	t_index		*tmp;

	tmp = (t_index *)malloc(sizeof(*tmp));
	if (tmp)
	{
		tmp->size = 0;
		tmp->first = NULL;
		tmp->last = NULL;
	}
	return (tmp);
}
