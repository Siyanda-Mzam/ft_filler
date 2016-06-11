/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 08:20:08 by simzam            #+#    #+#             */
/*   Updated: 2016/06/11 09:29:43 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include "ft_fc_print.h"

/* Reads through the board and attempts a valid play.
 * Provided that this look-ahead returns positive results.
 * Honey Badger will make the move.
 * @param board/piece: Stores the board/piece from input stream.
 * @param coords: The co-ordinates in the board.
 * @param pl_type: The player.
 * @param check: Boolean to flag if a player has been checked.
 */

static int		ft_test_pos(t_shape *board, t_coords coords, char pl_type)
{
	if (pl_type == 1 || pl_type == 3)
	{
		if (board->data[coords.x][coords.y] == 'O')
			return (1);
		if (board->data[coords.x][coords.y] == 'o')
			return (1);
	}
	if (pl_type == 2 || pl_type == 3)
	{
		if (board->data[coords.x][coords.y] == 'X')
			return (1);
		if (board->data[coords.x][coords.y] == 'x')
			return (1);
	}
	return (0);
}

static int		ft_attempt(t_coords test, t_shape *board, char plr, int *check)
{
	if (test.x >= board->wid || test.y >= board->len)
		return (0);
	else if (!*check && ft_test_pos(board, test, plr))
		*check = 1;
	else if (*check && ft_test_pos(board, test, plr))
		return (0);
	else if (ft_test_pos(board, test, 3))
		return (0);
	return (1);
}

static int		ft_look_ahead(t_shape *board, t_shape *piece, char player)
{
	int			check;
	t_coords	test;

	check = 0;
	piece->pos.x = -1;
	while (piece->data[++piece->pos.x])
	{
		piece->pos.y = -1;
		while (piece->data[piece->pos.x][++piece->pos.y])
		{
			if (piece->data[piece->pos.x][piece->pos.y] == '*')
			{
				test.x = board->pos.x + piece->pos.x;
				test.y = board->pos.y + piece->pos.y;
				if (!ft_attempt(test, board, player, &check))
					return (0);
			}
		}
	}
	if (!check || board->pos.x + piece->wid > board->wid)
		return (0);
	if (board->pos.y + piece->len >= board->len)
		return (0);
	return (1);
}

static void		ft_putcoord(int coord_1, int coord_2)
{
	ft_putnbr_fd(coord_1, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(coord_2, 1);
	ft_putchar_fd('\n', 1);
}

void			ft_play(t_shape *board, t_shape *piece, char player)
{
	board->pos.x = -1;
	while (board->data[++board->pos.x])
	{
		board->pos.y = -1;
		while (board->data[board->pos.x][++board->pos.y])
		{
			if (ft_look_ahead(board, piece, player))
			{
				ft_putcoord(board->pos.x, board->pos.y);
				return ;
			}
		}
	}
	ft_putcoord(0, 0);
}
