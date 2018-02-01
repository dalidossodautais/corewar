# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gricquie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 20:51:53 by gricquie          #+#    #+#              #
#    Updated: 2017/09/13 12:43:57 by gricquie         ###   ########.fr        #
#    Updated: 2017/03/15 14:40:22 by gricquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJDIR = objs/

HEADERDIR = includes/
HEADER = ft_printf.h libft.h array.h
HEADERFULL = $(addprefix $(HEADERDIR), $(HEADER))

PRINTF = ft_printf.c ft_fprintf.c \
		 printf_addparam.c \
		 printf_addpad.c printf_addprec.c \
		 printf_modinit.c printf_type.c printf_addapos.c \
		 printf_cutdouble.c printf_adddoubleprec.c printf_calcexp.c \
		 printf_color.c printf_flag_a.c printf_flag_b.c printf_flag_c.c \
		 printf_flag_lc.c printf_flag_d.c printf_flag_e.c printf_flag_f.c \
		 printf_flag_g.c printf_flag_n.c printf_flag_o.c printf_flag_p.c \
		 printf_flag_s.c printf_flag_ls.c printf_flag_u.c printf_flag_x.c \
		 printf_flag_prc.c printf_wrongconv.c

PRINTFDIR = printf/
PRINTFOBJS = $(PRINTF:.c=.o)
PRINTFFULL = $(addprefix $(OBJDIR), $(PRINTFOBJS))

ARRAY = ft_arraynew.c ft_arraydup.c ft_arraydel.c \
		ft_arraycat.c ft_arrayjoin.c ft_arraydeljoin.c \
		ft_arrayaddstrback.c ft_arrayaddstrfront.c \
		ft_arrayaddstrnback.c ft_arrayaddstrnfront.c \
		ft_arraycutfront.c ft_arraycutback.c \
		ft_arrayaddcharback.c ft_arrayaddcharfront.c\
		ft_arrayprint.c ft_arrayprintl.c ft_arrayprint_fd.c \
		ft_arrayrealloc.c ft_arrayaddbaseback.c \
		ft_arrayaddwcharback.c ft_arrayaddwcsback.c \
		ft_arrayaddnspace.c

ARRAYDIR = array/
ARRAYOBJS = $(ARRAY:.c=.o)
ARRAYFULL = $(addprefix $(OBJDIR), $(ARRAYOBJS))

MEM = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
	  ft_realloc.c ft_reversebyte.c \

MEMDIR = memory/
MEMOBJS = $(MEM:.c=.o)
MEMFULL = $(addprefix $(OBJDIR), $(MEMOBJS))

STR = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strndup.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isspace.c \
	  ft_isupper.c ft_islower.c ft_isprint.c ft_isallnumber.c \
	  ft_toupper.c ft_tolower.c \
	  ft_strdeljoin.c \
	  ft_atoi.c ft_itoabase.c ft_itoa.c ft_ctoa.c\
	  ft_strsplitcharset.c ft_addstr.c \
	  get_next_line.c \
	  ft_printtab.c ft_freetab.c \

STRDIR = string/
STROBJS = $(STR:.c=.o)
STRFULL = $(addprefix $(OBJDIR), $(STROBJS))

PUT = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putnbrl.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_putnbrl_fd.c ft_putwchar.c ft_putbase.c

PUTDIR = put/
PUTOBJS = $(PUT:.c=.o)
PUTFULL = $(addprefix $(OBJDIR), $(PUTOBJS))

LST = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c ft_lstdeljoin.c ft_lstprint.c ft_lstlen.c ft_lstaddback.c \
	  ft_lstsort.c

LSTDIR = list/
LSTOBJS = $(LST:.c=.o)
LSTFULL = $(addprefix $(OBJDIR), $(LSTOBJS))

BTREE = ft_btreeprint.c ft_btreenew.c ft_btreeaddnode.c \
		ft_btreegetfirst.c ft_btreedepth.c ft_btreenbnode.c \
		ft_btreedel.c ft_btreedelone.c \
		ft_btreerotateleft.c ft_btreerotateright.c \
		ft_btreegetnext.c

BTREEDIR = btree/
BTREEOBJS = $(BTREE:.c=.o)
BTREEFULL = $(addprefix $(OBJDIR), $(BTREEOBJS))

INT = ft_swap.c ft_min.c ft_max.c ft_intlen.c ft_unsignedintlen.c ft_baselen.c \
	  ft_sort.c ft_median.c ft_abs.c

INTDIR = int/
INTOBJS = $(INT:.c=.o)
INTFULL = $(addprefix $(OBJDIR), $(INTOBJS))

WCHAR = ft_wcslen.c ft_wcswrite.c \
		ft_wchartostr.c ft_wcstostr.c \
		ft_wcsdup.c ft_wcharbytelen.c \
		ft_wcslen.c ft_wcswrite.c \
		ft_wcsbytelen.c

WCHARDIR = wchar/
WCHAROBJS = $(WCHAR:.c=.o)
WCHARFULL = $(addprefix $(OBJDIR), $(WCHAROBJS))

OBJFULL = $(PRINTFFULL) \
		  $(ARRAYFULL) \
		  $(MEMFULL) \
		  $(STRFULL) \
		  $(PUTFULL) \
		  $(LSTFULL) \
		  $(BTREEFULL) \
		  $(INTFULL) \
		  $(WCHARFULL)

FLAGS = -Werror -Wextra -Wall

all : $(NAME)

$(NAME): $(OBJFULL) $(HEADERFULL)
	ar -rc $(NAME) $(OBJFULL)
	@ranlib $(NAME)

$(OBJDIR)%.o : $(PRINTFDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(OBJDIR)%.o : $(ARRAYDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(OBJDIR)%.o : $(MEMDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(OBJDIR)%.o : $(STRDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(OBJDIR)%.o : $(PUTDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(OBJDIR)%.o : $(LSTDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(OBJDIR)%.o : $(BTREEDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(OBJDIR)%.o : $(INTDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

$(OBJDIR)%.o : $(WCHARDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(HEADERDIR)

clean :
	rm -f $(OBJFULL)
	@rmdir $(OBJDIR) 2> /dev/null || true

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
