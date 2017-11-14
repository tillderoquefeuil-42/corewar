# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nflores <nflores@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/23 10:47:12 by nflores           #+#    #+#              #
#    Updated: 2016/06/30 17:48:52 by nflores          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

NAME2 = corewar

.PHONY: all, clean, fclean, re

all: $(NAME) $(NAME2)

$(NAME):
	make -C Assembleur/ && mv Assembleur/asm .

$(NAME2):
	make -C vm/ && mv vm/corewar .

clean:
	make -C Assembleur/ clean && make -C vm/ clean

fclean:
	make -C Assembleur/ fclean && make -C vm/ fclean
	rm -rf $(NAME) $(NAME2)
	rm -rf demo

re: fclean all

cp:
	cp -R /sgoinfre/goinfre/corewar demo
