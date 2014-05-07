/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:55:53 by sconso            #+#    #+#             */
/*   Updated: 2013/12/31 20:50:26 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ft_fc_mem.h>
# include <ft_fc_str.h>
# include <ft_fc_tests.h>
# include <ft_fc_print.h>
# include <ft_fc_conversion.h>

int			ft_match(char *s1, char *s2);
int			ft_nmatch(char *s1, char *s2);
void		ft_swap(int *a, int *b);
char		*ft_strrev(char *str);
#endif /* LIBFT_H */
