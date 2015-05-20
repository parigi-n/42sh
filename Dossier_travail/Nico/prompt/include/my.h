/*
** my.h for my in /home/vautie_a/rendu/Piscine_C_J09/ex_02
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Oct 10 21:03:48 2014 jules vautier
** Last update Fri May  8 10:40:05 2015 Jules Vautier
*/

#ifndef MY_H_
# define MY_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include "string.h"
# include "printf.h"
# include "wordtab.h"
# include "struct.h"
# include "list.h"
# include "mysh.h"
# include "pars.h"
# include "rc.h"
# include "prompt.h"

void	my_putchar(char c);
int	my_put_nbr(int nb);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *, char *);
char	*my_strcat(char *, char *);
char	*my_strcat_separ(char *, char *, char);
char	*my_strcpy(char *);
char	*my_strncpy(char *, int);
char	*add_chat(char *, int, char);
char	*decal(char *, int);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
int	my_strlcmp(char *, char *, int);
int	my_strcmp_op(char *, char *, int);
int	puterr(char *);

#endif /* !MY_H_ */
