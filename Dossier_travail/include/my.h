/*
** my.h for my in /home/vautie_a/rendu/Piscine_C_J09/ex_02
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Oct 10 21:03:48 2014 jules vautier
** Last update Sun Mar 15 19:48:09 2015 Jules Vautier
*/

#ifndef MY_H_
# define MY_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include "printf.h"
# include "wordtab.h"
# include "mysh.h"

void	my_putchar(char c);
int	my_put_nbr(int nb);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *, char *);
int	puterr(char *);

#endif /* !MY_H_ */
