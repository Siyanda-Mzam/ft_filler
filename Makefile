# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simzam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/10 09:17:10 by simzam            #+#    #+#              #
#    Updated: 2016/06/10 10:29:54 by simzam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CC = gcc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -pedantic -ansi -g -ggdb
INC = -I includes/ -I libft/includes/
LFLAGS = -L libft/ -lft

FILES = ft_filler.c ft_reader.c ft_playing.c

SRCDIR = src
OBJDIR = obj

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all 		: $(NAME)

$(NAME) 	: libft $(OBJDIR) $(OBJ)
				@make -C libft/ all
				@$(CC) $(CFLAGS) $(INC) -o $@ $(OBJ) $(LFLAGS)
				@echo "\033[42m$@\033[0m created!"

$(OBJDIR) 	:
				@/bin/mkdir $(OBJDIR);			\
				for DIR in $(SRCDIR);			\
				do								\
					/bin/mkdir $(OBJDIR)/$$DIR;	\
				done							\

$(addprefix $(OBJDIR)/, %.o) : %.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@/bin/echo -n "Creating objects in $(addprefix $(OBJDIR)/, $(SRCDIR)) : "
	@echo "\033[1;33m$(subst $(SRCDIR)/, , $(<:.c=.o))\033[0m"

run			: re
				@/usr/bin/clear
				@./$(NAME)

clean		:
				@/bin/rm -rf $(OBJDIR) a.out.dSYM
				@/bin/rm -f a.out
				@echo "\033[1;41mRemoving the honey badger objects...\033[0m\n\033[42mDONE!!!"

fclean		: clean
				@/bin/rm -f $(NAME)
				@echo "\033[1;40m$(NAME)\033[0m removed!"

libft		:
				@make -C libft all

libfclean	:
				@make -C libft fclean

libre		:
				@make -C libft re
				@make re

re			: fclean all

debug		: CFLAGS += $(DFLAGS)
debug		: re

.SILENT 	:
.PHONY		: all clean fclean re
