/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 20:53:52 by sconso            #+#    #+#             */
/*   Updated: 2013/12/31 20:56:46 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FC_PRINT_H
# define FT_FC_PRINT_H

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif /* FT_FC_PRINT_H */
