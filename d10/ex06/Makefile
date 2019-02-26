# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 16:34:38 by onahiz            #+#    #+#              #
#    Updated: 2018/09/20 23:34:54 by onahiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRCS = srcs/ft_doop.c srcs/ft_write.c

OBJS = ft_doop.o ft_write.o

HEAD = includes/ft.h includes/ft2.h

CC = gcc -Wall -Wextra -Werror 

all: $(HEAD)
	$(CC) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
