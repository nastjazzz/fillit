# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 10:05:27 by hhobert           #+#    #+#              #
#    Updated: 2019/11/24 19:10:20 by hhobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFILE = main.c list_func.c prepare.c logika.c validation.c help.c
OFILE = main.o list_func.o prepare.o logika.o validation.o help.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -c $(CFILE)
	gcc $(FLAGS) -o $(NAME) $(OFILE) -L "libft" -lft 
	
clean:
	make -C libft/ clean
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
