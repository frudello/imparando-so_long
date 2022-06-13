# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frudello <frudello@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 20:28:51 by frudello          #+#    #+#              #
#    Updated: 2022/06/12 17:52:06 by frudello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

P1		=	checker/
P2		=	errors/
P3		=	img_utils/
P4		=	map_utils/
P5		=	utils/

SL_SRC	=	so_long.c							\

SL_OBJ	=	$(SL_SRC:.c=.o)

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@ 

MLX		=	./libmlx.dylib


RM		=	rm -fr

$(NAME):	$(SL_OBJ)
			@(test -f $(MLX)  && echo "\033[32mMLX already built\033[0m") || (make -C ./mlx && mv mlx/libmlx.dylib .)
			$(CC) $(CFLAGS) -o $(NAME) $(SL_OBJ) $(MLX)
			@(echo "\033[32mSO_LONG>> Compiled\033[0m")

all:		$(NAME)
 
norme:
		@norminette $(SL_SRC)

clean:
			make clean -C mlx
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mSO_LONG>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mSO_LONG>> Project cleaned\033[0m"

re:			fclean all
			@echo "\033[0;92mSO_LONG>> Project cleaned and recompiled\033[0m"

re.all:		fclean

.PHONY:		all clean fclean re