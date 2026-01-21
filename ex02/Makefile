# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 21:06:47 by yanzhao           #+#    #+#              #
#    Updated: 2026/01/20 14:14:11 by yanzhao          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#sed 's/\[.*\]//'

NAME=account

OBJS_PATH=./objs/

SRCS=Account.cpp tests.cpp

OBJS=$(addprefix $(OBJS_PATH), $(SRCS:.cpp=.o))

DEPS=$(addprefix $(OBJS_PATH), $(SRCS:.cpp=.d))

HEADER_PATH=./

CC=c++

CFLAGS= -Wall -Wextra -Werror -std=c++98

DEPFLAGS=-MMD -MP

-include $(DEPS)

all:init $(NAME)

init:
	@mkdir -p $(OBJS_PATH)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_PATH)%.o:%.cpp | init
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(HEADER_PATH) -c $< -o $@

clean:
	rm -rf $(OBJS_PATH)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
