##
## Makefile for MAKEFILE in /home/vautie_a/rendu/CPE_2014_Pushswap
## 
## Made by jules vautier
## Login   <vautie_a@epitech.net>
## 
## Started on  Mon Dec  8 09:12:47 2014 jules vautier
## Last update Thu Apr 30 12:23:39 2015 Nicolas PARIGI
##

CC		= gcc -g

SRC		= alias.c \
		  my_word_to_tab_custom.c \
		  my_put.c \
		  fct_tab.c \
		  my_strcmp.c \
		  get_next_line.c \
		  epur_str.c \
		  my_word_to_tab_deter.c \
		  my_str_fct.c \
		  add_char.c

OBJ		= $(SRC:.c=.o)

#CFLAGS		+= -Wextra -Wall
#CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I./include/

NAME		= alias

LDFLAGS		=

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
