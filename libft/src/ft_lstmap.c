/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 14:49:03 by sconso            #+#    #+#             */
/*   Updated: 2013/12/27 23:14:32 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_list.h>
#include <ft_fc_mem.h>
#include <string.h>
#include <stdlib.h>

static t_list	*ft_lstaddlast(t_list **lst, void const *content, size_t size)
{
	void		*contentcpy;
	t_list		*tmp;
	t_list		*list;

	if (lst == NULL)
		return (0);
	tmp = (t_list *)malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (0);
	list = *lst;
	contentcpy = malloc(size);
	ft_memcpy(contentcpy, content, size);
	tmp->content = contentcpy;
	tmp->next = NULL;
	if (*lst)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = tmp;
	}
	else
		*lst = tmp;
	return (tmp);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;

	new = 0;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		tmp = f(lst);
		ft_lstaddlast(&new, tmp->content, tmp->content_size);
		lst = lst->next;
	}
	return (new);
}
