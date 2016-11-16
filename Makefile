# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nweizman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/31 13:11:22 by nweizman          #+#    #+#              #
#    Updated: 2016/10/05 11:16:40 by nweizman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit

CFLAGS =	-Wall -Werror -Wextra

SRCS =		src/help_functions.c	\
				main.c				\
				src/map_solver.c	\
				read/read_file.c 	\
				read/help_read.c	\
				src/map_functions.c	\
				read/piece_stock.c	

OBJS =		$(SRCS:.c=.o)

CC =		clang

LIBFT =		-L libft -l ft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re