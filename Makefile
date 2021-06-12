# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:15:26 by tjmari            #+#    #+#              #
#    Updated: 2021/06/12 13:06:45 by mmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Werror


SRCS = ./pipex.c ./libft_tools.c ./libft_tools2.c ./tools.c ./execute.c

# FILES = $(SRCS)|./Makefile|./pipex.h 

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS)	-o $(NAME) -fsanitize=address

# clean:
# 	rm -- ^($(FILES))
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
