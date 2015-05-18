##
## Makefile for MAKEFILE in /home/vautie_a/rendu/CPE_2014_Pushswap
## 
## Made by jules vautier
## Login   <vautie_a@epitech.net>
## 
## Started on  Mon Dec  8 09:12:47 2014 jules vautier
## Last update Sat May 16 18:05:14 2015 Nicolas PARIGI
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
		src/42shrc/alias.c \
		src/42shrc/init.c \
		src/builtin/cd.c \
		src/builtin/builtin.c \
		src/builtin/exit.c \
		src/builtin/alias.c \
		src/get_cmd/alias.c \
		src/get_cmd/key.c \
		src/get_cmd/curse.c \
		src/get_cmd/buff.c \
		src/get_cmd/get_str.c \
		src/get_cmd/get_str_raw.c \
		src/get_cmd/init.c \
		src/get_cmd/fct_get_str.c \
		src/get_cmd/auto_comp.c \
		src/pars/parseur.c \
		src/pars/len_pars.c \
		src/pars/parsing.c \
		src/printf/mainprintf.c \
		src/printf/fct_printf.c \
		src/wordtab/my_show_tab.c \
		src/wordtab/fct_tab.c \
		src/wordtab/my_word_to_tab.c \
		src/wordtab/my_word_to_tab_custom.c \
		src/wordtab/my_word_to_tab_deter.c \
		src/wordtab/epur_str.c \
		src/wordtab/tabcpy.c \
		src/wordtab/freetab.c \
		src/wordtab/tab_env.c \
		src/list/pars_list.c \
		src/list/list.c \
		src/list/fct_list.c \
		src/shared/fct_char.c \
		src/shared/get_next_line.c \
		src/shared/puterr.c \
		src/shared/my_put.c \
		src/shared/strcmp.c \
		src/shared/strcat.c \
		src/shared/strcpy.c \
		src/shared/decal.c \
		src/prompt/prompt.c \
		src/prompt/fct_prompt_misc.c \
		src/prompt/fct_prompt_time.c \
		src/prompt/fct_prompt_time_2.c \
		src/prompt/fct_prompt_dir_and_name.c \
		src/prompt/pwd_home.c

OBJ		= $(SRC:.c=.o)

CFLAGS		+= -I./include/
CFLAGS		+= -Wextra -Wall

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
