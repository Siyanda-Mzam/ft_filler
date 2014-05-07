/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addindlist.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:53:06 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 22:59:57 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_dlist			*ft_addindlist(t_index *list, char *data, unsigned int pos)
{
	t_dlist		*node;
	t_dlist		*tmp;

	if (list == NULL || pos <= 0 || pos > list->size + 1 || !data)
		return (0);
	if (pos == 1)
		return (ft_addfirstdlist(list, data));
	if (pos == list->size + 1)
		return (ft_addlastdlist(list, data));
	node = (t_dlist *)malloc(sizeof(*node));
	if (node)
	{
		tmp = list->first;
		while (--pos && tmp)
			tmp = tmp->next;
		node->name = data;
		node->next = tmp;
		node->prev = tmp->prev;
		tmp->prev->next = node;
		tmp->prev = node;
		list->size++;
	}
	return (node);
}
