/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 20:48:11 by sconso            #+#    #+#             */
/*   Updated: 2014/01/26 21:44:57 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FC_MEM_H
# define FT_FC_MEM_H

# include <string.h>

void		ft_bzero(void *str, size_t n);
void		*ft_memset(void *str, int character, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		ft_free(char **str);

#endif /* FT_FC_MEM_H */
