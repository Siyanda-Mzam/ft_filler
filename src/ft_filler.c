/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 19:47:49 by sconso            #+#    #+#             */
/*   Updated: 2014/01/27 00:00:59 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_filler.h>
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	t_shape		*board;
	t_shape		*piece;
	char		player;

	player = 0;
	board = (t_shape *)malloc(sizeof(*board));
	piece = (t_shape *)malloc(sizeof(*piece));
	while (ft_read(board, piece, &player))
		ft_play(board, piece, player);
	return (0);
}
