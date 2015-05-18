##
## Makefile for MAKEFILE in /home/vautie_a/rendu/CPE_2014_Pushswap
## 
## Made by jules vautier
## Login   <vautie_a@epitech.net>
## 
## Started on  Mon Dec  8 09:12:47 2014 jules vautier
## Last update Thu Apr 30 18:16:13 2015 Martin PELLEMOINE
##

SRC		= src/main.c \
		src/pipe.c \
		src/write.c \
		src/mysh.c \
		src/choice_type.c \
		src/exe_command.c \
		src/exe_solo.c \
		src/find_path.c \
		src/builtin.c \
		src/my_getenv.c \
		src/cd.c \
		src/my_prompt.c \
		src/signal.c \
		src/pars/curse.c \
		src/pars/buff.c \
		src/pars/parsing.c \
		src/pars/auto_comp.c \
		src/pars/parseur.c \
		src/pars/get_str.c \
		src/pars/fct_get_str.c \
		src/printf/mainprintf.c \
		src/printf/fct_printf.c \
		src/wordtab/my_show_tab.c \
		src/wordtab/fct_tab.c \
		src/wordtab/my_word_to_tab.c \
		src/wordtab/epur_str.c \
		src/wordtab/tabcpy.c \
		src/wordtab/freetab.c \
		src/list/pars_list.c \
		src/list/list.c \
		src/list/fct_list.c \
		src/shared/puterr.c \
		src/shared/my_put.c \
		src/shared/strcmp.c \
		src/shared/my_str_fct.c

OBJ		= $(SRC:.c=.o)

CFLAGS		+= -Wextra -Wall
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I./include/

NAME		= mysh

LDFLAGS		=

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g -lncurses

cl:		$(NAME) clean

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re cl
