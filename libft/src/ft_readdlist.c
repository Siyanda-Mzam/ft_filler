/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:56:59 by sconso            #+#    #+#             */
/*   Updated: 2013/12/01 18:57:10 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <ft_fc_print.h>

void			ft_readdlist(t_index *list, char direction)
{
	t_dlist		*tmp;

	if (direction == 0)
		tmp = list->first;
	else
		tmp = list->last;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putstr(" > ");
		if (direction == 0)
			tmp = tmp->next;
		else
			tmp = tmp->prev;
	}
	ft_putstr("NULL");
}
