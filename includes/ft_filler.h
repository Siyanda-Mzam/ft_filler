/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 22:31:31 by sconso            #+#    #+#             */
/*   Updated: 2014/01/26 23:08:01 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

typedef struct		s_coords
{
	int				x;
	int				y;
}					t_coords;


typedef struct		s_shape
{
	char			**data;
	int				l;
	int				h;
	t_coords		pos;
}					t_shape;

int				ft_read(t_shape *board, t_shape *piece, char *player);
void			ft_play(t_shape *board, t_shape *piece, char player);

#endif /* FT_FILLER_H */
