# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 21:27:03 by yanzhao           #+#    #+#              #
#    Updated: 2026/01/26 19:17:55 by yanzhao          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=PhoneBook

OBJS_PATH=./objs/

SRCS=Contact.cpp PhoneBook.cpp main.cpp

OBJS=$(addprefix $(OBJS_PATH), $(SRCS:.cpp=.o))

DEPS=$(addprefix $(OBJS_PATH), $(SRCS:.cpp=.d))

HEADER_PATH=./

CC=c++

CFLAGS= -Wall -Wextra -Werror -std=c++98

DEPFLAGS=-MMD -MP

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_PATH)%.o:%.cpp
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(HEADER_PATH) -c $< -o $@

clean:
	rm -rf $(OBJS_PATH)

fclean:clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

