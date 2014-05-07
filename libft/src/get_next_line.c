/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:12:10 by sconso            #+#    #+#             */
/*   Updated: 2014/01/26 23:35:44 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <ft_fc_str.h>
#include <ft_fc_print.h>
#include <ft_fc_mem.h>
#include <stdlib.h>
#include <unistd.h>

static char			*ft_exit(char **str)
{
	ft_free(str);
	return (0);
}

char				*get_next_line(int const fd)
{
	static char		*tmp;
	char			*buf;
	char			*size;
	int				ret;

	tmp = (tmp ? tmp : ft_strdup(""));
	if (fd < 0 || BUFF_SIZE < 1)
		return (ft_exit(&tmp));
	buf = ft_strnew(BUFF_SIZE + 1);
	if (!buf)
		return (ft_exit(&tmp));
	while (!(size = ft_strchr(tmp, '\n')) && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		tmp = ft_strcleanjoin(tmp, buf);
	}
	ft_free(&buf);
	if (tmp[0] && (size || (size = ft_strrchr(tmp, 0))))
	{
		buf = ft_strsub(tmp, 0, size - tmp);
		ft_free(&tmp);
		tmp = (size[0] ? ft_strdup(size + 1) : ft_strdup(""));
		return (buf);
	}
	return (ft_exit(&tmp));
}
