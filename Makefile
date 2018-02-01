# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gricquie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 20:51:53 by gricquie          #+#    #+#              #
#    Updated: 2018/01/08 12:36:01 by gricquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
VM = corewar

ASM_SRCS =	op.c \
			asm_main.c \
			error.c \
			compile.c \
			get_name_and_comment.c \
			is_comment.c \
			search_and_stock_label.c \
			is_label.c \
			print_label.c free_label.c \
			convert_asm_to_bytecode.c \
			write_instr_in_result.c \
			convert_param.c \
			get_label_value.c \
			create_and_write_file.c \
			stock_param_type.c

VM_SRCS	=	op.c \
			vm_main.c \
			error.c \
			read_args.c \
			read_champs.c \
			dump.c \
			init_arena.c \
			intro_champs.c \
			init_process.c \
			run.c \
			change_carry.c \
			enter_new_op_in_process.c \
			check_live.c \
			announce_winner.c \
			copy_arena.c \
			copy_in_arena.c \
			advance_pc.c \
			check_ocp.c \
			check_reg.c \
			get_op.c \
			print_op_mem.c \
			get_next_process_nb.c \
			do_op.c \
			get_param.c \
			op_live.c \
			op_load.c \
			op_store.c \
			op_add.c \
			op_sub.c \
			op_and.c \
			op_or.c \
			op_xor.c \
			op_zjmp.c \
			op_ldi.c \
			op_sti.c \
			op_fork.c \
			op_lld.c \
			op_lldi.c \
			op_lfork.c \
			op_aff.c \
			print_ncurses.c \
			handle_win.c \
			graph_ncurses.c

ASM_OBJS = $(ASM_SRCS:.c=.o)
VM_OBJS = $(VM_SRCS:.c=.o)

HEADER = ft_printf.h libft.h array.h get_next_line.h
ASM_HEADER = asm.h
VM_HEADER = vm.h
LIBFT = ft
LIBFTNAME = libft/libft.a

ASM_DIR = asm_srcs/
VM_DIR = vm_srcs/
LIBFTDIR = libft/
ASM_ODIR = asm_objs/
VM_ODIR = vm_objs/
HEADERDIR = includes/

ASMFULL = $(addprefix $(ASM_ODIR), $(ASM_OBJS))
VMFULL = $(addprefix $(VM_ODIR), $(VM_OBJS))
HEADERFULL = $(addprefix $(HEADERDIR), $(HEADER))
ASM_HEADERFULL = $(addprefix $(HEADERDIR), $(ASM_HEADER))
VM_HEADERFULL = $(addprefix $(HEADERDIR), $(VM_HEADER))

FLAGS = -Wall \
 		-Wextra \
 		-Werror \
 		-O3 \
		

all : $(ASM) $(VM)

$(ASM) : $(ASMFULL) $(HEADERFULL) $(LIBFTNAME) $(ASM_HEADERFULL)
	gcc $(FLAGS) -o $(ASM) $(ASMFULL) -I$(HEADERDIR) -L$(LIBFTDIR) -l$(LIBFT)

$(VM) : $(VMFULL) $(LIBFTNAME) $(HEADERFULL) $(VM_HEADERFULL)
	gcc $(FLAGS) -o $(VM) $(VMFULL) -I$(HEADERDIR) -L$(LIBFTDIR) -l$(LIBFT) -lncurses

libft : $(LIBFTNAME)

$(LIBFTNAME) : 
	make -C $(LIBFTDIR)

$(ASM_ODIR)%.o : $(ASM_DIR)%.c $(LIBFTNAME) $(HEADERFULL) $(ASM_HEADERFULL)
	@mkdir $(ASM_ODIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(VM_ODIR)%.o : $(VM_DIR)%.c $(LIBFTNAME) $(HEADERFULL) $(VM_HEADERFULL)
	@mkdir $(VM_ODIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

clean :
	@make -C $(LIBFTDIR) clean
	rm -f $(ASMFULL) $(VMFULL)
	rmdir $(ASM_ODIR) $(VM_ODIR) 2> /dev/null || true

fclean : clean
	@make -C $(LIBFTDIR) fclean
	rm -f $(ASM) $(VM)

re : fclean all

.PHONY : all clean fclean re
