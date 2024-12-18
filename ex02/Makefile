# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 12:57:11 by pleander          #+#    #+#              #
#    Updated: 2024/12/18 10:06:35 by pleander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := AccountTests
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
SOURCES := Account.cpp tests.cpp

OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
		$(CXX) $(OBJECTS) -I ./include -o $(NAME)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -I ./include -c $< -o $@

.PHONY: clean
clean:
		rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
		rm -f $(NAME)

.PHONY: re
re: fclean all
