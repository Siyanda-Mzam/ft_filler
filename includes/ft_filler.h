/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 08:20:08 by simzam            #+#    #+#             */
/*   Updated: 2016/06/10 12:29:26 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

/* The interface file */

typedef struct		s_coordinates
{
	int				x;
	int				y;
}					t_coords;


typedef struct		s_shape
{
	char			**data;
	int				len;
	int				wid;
	t_coords		pos;
}					t_shape;

int					ft_read(t_shape *board, t_shape *piece, char *player);
void				ft_play(t_shape *board, t_shape *piece, char player);

#endif
