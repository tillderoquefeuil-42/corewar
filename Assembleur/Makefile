#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 11:33:12 by tde-roqu          #+#    #+#              #
#    Updated: 2016/08/05 13:37:26 by tde-roqu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm

FCT = functions/main.c functions/asm.c functions/champ_process.c \
functions/ft_error_asm.c functions/get_next_line.c functions/ft_inst_checks.c \
functions/ft_struc_init.c functions/ft_para.c functions/ft_header.c \
functions/ft_file_ft.c functions/ft_lab_ft.c functions/ft_para_w.c \
functions/ft_write_inst.c functions/ft_create_file.c \
functions/ft_normization.c functions/ft_coding_bit.c \
functions/ft_str_du_turfu.c

INST = instruc/ft_live.c instruc/ft_ld.c instruc/ft_st.c instruc/ft_add.c \
instruc/ft_sub.c instruc/ft_and.c instruc/ft_or.c instruc/ft_xor.c \
instruc/ft_zjmp.c instruc/ft_ldi.c instruc/ft_sti.c instruc/ft_fork.c \
instruc/ft_lld.c instruc/ft_lldi.c instruc/ft_lfork.c instruc/ft_aff.c

SRC = $(FCT) $(INST)

OBJ = main.o asm.o champ_process.o ft_error_asm.o get_next_line.o \
ft_inst_checks.o ft_struc_init.o ft_para.o ft_live.o ft_ld.o ft_st.o ft_add.o \
ft_sub.o ft_and.o ft_or.o ft_xor.o ft_zjmp.o ft_ldi.o ft_sti.o ft_fork.o \
ft_lld.o ft_lldi.o ft_lfork.o ft_aff.o ft_header.o ft_file_ft.o ft_lab_ft.o \
ft_para_w.o ft_write_inst.o ft_create_file.o ft_normization.o ft_coding_bit.o \
ft_str_du_turfu.o

HEAD = includes/

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ft_printf/ fclean && make -C ft_printf/
	gcc $(FLAGS) -I $(HEAD) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -I $(HEAD) -L ft_printf/ -lftprintf

clean:
	make -C ft_printf/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all