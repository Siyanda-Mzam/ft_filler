/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 22:33:51 by sconso            #+#    #+#             */
/*   Updated: 2014/01/26 23:31:47 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_filler.h>
#include <ft_fc_print.h>

static int		ft_testpos(t_shape *board, t_coords coords, char type)
{
	if (type == 1 || type == 3)
	{
		if (board->data[coords.x][coords.y] == 'O')
			return (1);
		if (board->data[coords.x][coords.y] == 'o')
			return (1);
	}
	if (type == 2 || type == 3)
	{
		if (board->data[coords.x][coords.y] == 'X')
			return (1);
		if (board->data[coords.x][coords.y] == 'x')
			return (1);
	}
	return (0);
}

static int		ft_trying(t_coords c, t_shape *board, char p, int *check)
{
	if (c.x >= board->h || c.y >= board->l)
		return (0);
	else if (!*check && ft_testpos(board, c, p))
		*check = 1;
	else if (*check && ft_testpos(board, c, p))
		return (0);
	else if (ft_testpos(board, c, 3))
		return (0);
	return (1);
}

static int		ft_try(t_shape *board, t_shape *piece, char player)
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
				if (!ft_trying(test, board, player, &check))
					return (0);
			}
		}
	}
	if (!check || board->pos.x + piece->h > board->h)
		return (0);
	if (board->pos.y + piece->l >= board->l)
		return (0);
	return (1);
}

static void		ft_putcoord(int c1, int c2)
{
	ft_putnbr_fd(c1, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(c2, 1);
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
			if (ft_try(board, piece, player))
			{
				ft_putcoord(board->pos.x, board->pos.y);
				return ;
			}
		}
	}
	ft_putcoord(0, 0);
}
