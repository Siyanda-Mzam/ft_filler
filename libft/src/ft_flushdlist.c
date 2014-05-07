/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flushdlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:56:31 by sconso            #+#    #+#             */
/*   Updated: 2013/12/01 18:56:45 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_index		*ft_flushdlist(t_index *list)
{
	t_dlist		*tmp;

	if (list == NULL || list->first == NULL)
		return (NULL);
	tmp = list->first;
	while (tmp)
	{
		list->first = tmp->next;
		free(tmp);
		tmp = list->first;
	}
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}
