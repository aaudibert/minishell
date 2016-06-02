# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 16:20:10 by aaudiber          #+#    #+#              #
#    Updated: 2016/06/02 19:53:35 by aaudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./src/minishell.c\
	  ./src/get_next_line.c\
	  ./src/get_name.c\
	  ./src/print_prompt.c\
	  ./src/ft_initenv.c\
	  ./src/ft_setenv.c\
	  ./src/ft_unsetenv.c\
	  ./src/free_struct.c\
	  ./src/valid_cmd.c\
	  ./src/ex_cmd.c\
	  ./src/ft_chdir.c\
	  ./src/handle_pwd.c\
	  ./src/signhandler.c\

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	@/bin/echo "-----Compilating sources-----"
	@make -C ./libft
	@/bin/echo "---Done---"
	@/bin/echo "-----Creating executable-----"
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I./libft/includes/ ./libft/libft.a
	@/bin/echo "---Done---"

clean:
	@/bin/echo "-----cleaning-----"
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean:
	@/bin/echo "-----fcleaning-----"
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
