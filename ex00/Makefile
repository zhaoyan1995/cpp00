#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 21:27:03 by yanzhao           #+#    #+#              #
#    Updated: 2026/01/26 19:24:08 by yanzhao          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megaphone

SRCS=megaphone.cpp

OBJS=$(SRCS:.cpp=.o)

CC=c++

FLAGS= -Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
