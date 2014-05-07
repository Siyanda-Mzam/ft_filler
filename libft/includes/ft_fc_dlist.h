/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_dlist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:17:53 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 18:17:56 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FC_DLIST_H
# define FT_FC_DLIST_H

typedef struct			s_dlist
{
	char				*name;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}						t_dlist;

typedef struct			s_index
{
	unsigned int		size;
	t_dlist				*first;
	t_dlist				*last;
}						t_index;

enum					e_direction
{
	FORWARD, BACKWARD
};

t_index			*ft_createdlist(void);
t_dlist			*ft_addfirstdlist(t_index *list, char *data);
t_dlist			*ft_addlastdlist(t_index *list, char *data);
t_dlist			*ft_addindlist(t_index *list, char *data, unsigned int pos);
t_dlist			*ft_addalphaindlist(t_index *list, char *data);
t_dlist			*ft_addralphaindlist(t_index *list, char *data);
t_index			*ft_deletefirstdlist(t_index *list);
t_index			*ft_deletelastdlist(t_index *list);
t_index			*ft_deleteindlist(t_index *list, unsigned int position);
t_index			*ft_flushdlist(t_index *list);
void			ft_readdlist(t_index *list, char direction);

#endif /* FT_FC_DLIST_H */
