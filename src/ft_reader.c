/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 22:32:34 by sconso            #+#    #+#             */
/*   Updated: 2014/01/26 23:32:52 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_filler.h>
#include <ft_fc_tests.h>
#include <ft_fc_mem.h>
#include <ft_fc_str.h>
#include <get_next_line.h>
#include <stdlib.h>

static void		ft_getboard(char *line, t_shape *board)
{
	int			i;
	t_coords	coords;

	i = 8;
	coords.x = 0;
	coords.y = 0;
	while (!ft_isdigit(line[i]))
		++i;
	while (ft_isdigit(line[i]))
		coords.x = coords.x * 10 + (line[i++] - '0');
	board->data = (char **)malloc((coords.x + 2) * sizeof(char *));
	board->data[coords.x + 1] = NULL;
	while (ft_isdigit(line[++i]))
		coords.y = coords.y * 10 + (line[i] - '0');
	i = -1;
	line = get_next_line(0);
	ft_free(&line);
	board->h = coords.x + 1;
	board->l = coords.y + 1;
	while (++i <= coords.x && (line = get_next_line(0)) != 0)
	{
		board->data[i] = ft_strdup(&line[4]);
		ft_free(&line);
	}
}

static void		ft_getpiece(char *line, t_shape *piece)
{
	int			i;
	t_coords	coords;

	i = 6;
	coords.x = 0;
	coords.y = 0;
	while (!ft_isdigit(line[i]))
		++i;
	while (ft_isdigit(line[i]))
		coords.x = coords.x * 10 + (line[i++] - '0');
	piece->data = (char **)malloc((coords.x + 1) * sizeof(char *));
	piece->data[coords.x] = NULL;
	while (ft_isdigit(line[++i]))
		coords.y = coords.y * 10 + (line[i] - '0');
	i = -1;
	ft_free(&line);
	piece->h = coords.x;
	piece->l = coords.y;
	while (++i < coords.x && (line = get_next_line(0)))
	{
		piece->data[i] = ft_strdup(line);
		ft_free(&line);
	}
}

static char		ft_getplayer(char *line)
{
	char		*tmp;

	tmp = line;
	while (*tmp != 'p')
		++tmp;
	++tmp;
	ft_free(&line);
	return (*tmp - '0');
}

int				ft_read(t_shape *board, t_shape *piece, char *player)
{
	char	*line;
	int		size;

	size = 0;
	while ((line = get_next_line(0)) != 0)
	{
		if (!*player && ft_strstr(line, "./filler"))
			*player = ft_getplayer(line);
		else if (ft_strncmp(line, "Plateau", 6) == 0)
			ft_getboard(line, board);
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_getpiece(line, piece);
			return (1);
		}
	}
	return (0);
}
