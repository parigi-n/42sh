##
## Makefile for MAKEFILE in /home/vautie_a/rendu/CPE_2014_Pushswap
## 
## Made by jules vautier
## Login   <vautie_a@epitech.net>
## 
## Started on  Mon Dec  8 09:12:47 2014 jules vautier
## Last update Sun May 17 19:24:20 2015 Jules Vautier
##

SRC		= src/main.c \
		src/env.c \
		src/pipe.c \
		src/write.c \
		src/mysh.c \
		src/choice_type.c \
		src/exe_command.c \
		src/exe_solo.c \
		src/find_path.c \
		src/my_getenv.c \
		src/signal.c \
		src/tab_env.c \
		src/42shrc/alias.c \
		src/42shrc/init.c \
		src/builtin/cd.c \
		src/builtin/builtin.c \
		src/builtin/exit.c \
		src/builtin/alias.c \
		src/get_cmd/alias.c \
		src/get_cmd/curse.c \
		src/get_cmd/buff.c \
		src/get_cmd/unraw_get_str.c \
		src/get_cmd/raw_get_str.c \
		src/get_cmd/init.c \
		src/get_cmd/fct_get_str.c \
		src/get_cmd/auto_comp.c \
		src/pars/type.c \
		src/pars/parseur.c \
		src/pars/len_pars.c \
		src/pars/parsing.c \
		src/list/pars_list.c \
		src/list/list.c \
		src/list/fct_list.c \
		src/lib/printf/mainprintf.c \
		src/lib/printf/fct_printf.c \
		src/lib/wordtab/my_show_tab.c \
		src/lib/wordtab/fct_tab.c \
		src/lib/wordtab/my_word_to_tab.c \
		src/lib/wordtab/my_word_to_tab_custom.c \
		src/lib/wordtab/epur_str.c \
		src/lib/wordtab/tabcpy.c \
		src/lib/wordtab/freetab.c \
		src/lib/shared/fct_char.c \
		src/lib/shared/get_next_line.c \
		src/lib/shared/puterr.c \
		src/lib/shared/my_putchar.c \
		src/lib/shared/my_putstr.c \
		src/lib/shared/my_putnbr.c \
		src/lib/shared/my_strlen.c \
		src/lib/shared/strcmp.c \
		src/lib/shared/my_getnbr.c \
		src/lib/shared/strcat.c \
		src/lib/shared/strcpy.c \
		src/lib/shared/decal.c

OBJ		= $(SRC:.c=.o)

CFLAGS		+= -Wextra -Wall
CFLAGS		+= -ansi -pedantic -g
CFLAGS		+= -I./include/

NAME		= 42sh

LDFLAGS		=

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

cl:		$(NAME) clean

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re cl
