/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 08:20:08 by simzam            #+#    #+#             */
/*   Updated: 2016/06/10 12:38:45 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include "stdlib.h"
#include <unistd.h>

/* The entry-point of the program */

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
