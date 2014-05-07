#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconso <sconso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:30:01 by sconso            #+#    #+#              #
#    Updated: 2014/01/26 21:45:13 by sconso           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
ft_match.c ft_nmatch.c ft_swap.c ft_strrev.c \
ft_createdlist.c ft_addfirstdlist.c ft_addlastdlist.c ft_addindlist.c \
ft_addalphaindlist.c ft_addralphaindlist.c ft_deletefirstdlist.c \
ft_deletelastdlist.c ft_deleteindlist.c ft_flushdlist.c ft_readdlist.c \
get_next_line.c ft_strcleanjoin.c ft_free.c

FLAGS = -Wall -Wextra -Werror

SRCDIR = ./src

INCLUDE = ./includes
SRC = $(addprefix $(SRCDIR)/, $(FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $^ -I $(INCLUDE)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

release: FLAGS += -O2
release: re
