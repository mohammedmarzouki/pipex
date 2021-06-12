# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:15:26 by tjmari            #+#    #+#              #
#    Updated: 2021/06/12 14:21:43 by mmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Werror

LIB = pipex.h

SRCS = ./pipex.c ./libft_tools.c ./libft_tools2.c ./tools.c ./execute.c


all: $(NAME)

$(NAME): $(LIB) $(SRCS)
	@gcc $(FLAGS) $(SRCS)	-o $(NAME)

clean:
	@rm -f $(NAME)
	
fclean: clean

re: fclean all

.PHONY: all clean fclean re
