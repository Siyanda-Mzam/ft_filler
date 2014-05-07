/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:34:03 by sconso            #+#    #+#             */
/*   Updated: 2013/12/16 20:31:54 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_list.h>
#include <ft_fc_mem.h>
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;
	void		*contentcpy;
	size_t		content_sizecpy;

	content_sizecpy = content_size;
	tmp = (t_list *)malloc(sizeof(*tmp));
	if (tmp)
	{
		if (content == 0)
		{
			content_sizecpy = 0;
			tmp->content = NULL;
		}
		else
		{
			contentcpy = malloc(content_sizecpy);
			ft_memcpy(contentcpy, content, content_sizecpy);
			tmp->content = contentcpy;
		}
		tmp->content_size = content_sizecpy;
		tmp->next = 0;
	}
	else
		return (0);
	return (tmp);
}
