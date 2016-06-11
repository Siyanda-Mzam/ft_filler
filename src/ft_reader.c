/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 08:20:08 by simzam            #+#    #+#             */
/*   Updated: 2016/06/11 09:48:40 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include "ft_fc_tests.h"
#include "ft_fc_mem.h"
#include "ft_fc_str.h"
#include "get_next_line.h"
#include <stdlib.h>

/* Scans the input stream and extracts:
 * The Player
 * The Board and 
 * The piece
 * @param line: Stores one line of the input stream
 * @param board/piece: Stores the board/piece from input stream.
 * @param player: Stores the char representing the player.
 */

static void		ft_get_board(char *line, t_shape *board)
{
	int			i;
	t_coords	coords;

	i = 8;
	coords.x = 0;
	coords.y = 0;
	while (!ft_isdigit(line[i]))
		++i;
	while (ft_isdigit(line[i]))
		coords.y = coords.y * 10 + (line[i++] - '0');
	board->data = (char **)malloc((coords.x + 2) * sizeof(char *));
	board->data[coords.x + 1] = NULL;
	while (ft_isdigit(line[++i]))
		coords.x = coords.x * 10 + (line[i] - '0');
	i = -1;
	line = get_next_line(0);
	ft_free(&line);
	board->wid = coords.x + 1;
	board->len = coords.y + 1;
	while (++i <= coords.x && (line = get_next_line(0)) != 0)
	{
		board->data[i] = ft_strdup(&line[4]);
		ft_free(&line);
	}
}

static void		ft_get_piece(char *line, t_shape *piece)
{
	int			i;
	t_coords	coords;

	i = 6;
	coords.x = 0;
	coords.y = 0;
	while (!ft_isdigit(line[i]))
		++i;
	while (ft_isdigit(line[i]))
		coords.y = coords.y * 10 + (line[i++] - '0');
	piece->data = (char **)malloc((coords.y + 1) * sizeof(char *));
	piece->data[coords.y] = NULL;
	while (ft_isdigit(line[++i]))
		coords.x = coords.x * 10 + (line[i] - '0');
	i = -1;
	ft_free(&line);
	piece->wid = coords.x;
	piece->len = coords.y;
	while (++i < coords.x && (line = get_next_line(0)))
	{
		piece->data[i] = ft_strdup(line);
		ft_free(&line);
	}
}

static int		ft_get_player(char *line)
{
	char		*s;

	s = line;
	while (*s != 'p')
		++s;
	++s;
	ft_free(&line);
	return ((*s - '0'));
}

int				ft_read(t_shape *board, t_shape *piece, char *player)
{
	char	*line;

	while ((line = get_next_line(0)) != 0)
	{
		if (!*player && ft_strstr(line, "./filler"))
			*player = ft_get_player(line);
		else if (ft_strncmp(line, "Plateau", 2) == 0)
			ft_get_board(line, board);
		else if (ft_strncmp(line, "Piece", 2) == 0)
		{
			ft_get_piece(line, piece);
			return (1);
		}
	}
	return (0);
}
