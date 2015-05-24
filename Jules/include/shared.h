/*
** shared.h for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun May 17 12:06:37 2015 david sebaoun
** Last update Sun May 24 17:42:53 2015 Nicolas PARIGI
*/

#ifndef SHARED_H_
# define SHARED_H_

# include <unistd.h>
# include <stdlib.h>

# define SUCCESS (0)
# define ERROR	-1
# define QUOTE	39
# define DQUOTE	34

int		my_putnbr(int nb);
int		my_putstr(const char *str);
int		puterr(const char *str);
int		my_putchar(const char c);
int		my_strlen(const char *str);
int		char_cmp_str(char c, char *str);
int		my_strcmp(const char *str, const char *new);
int		my_strlcmp(const char *str, const char *new, int nb);
int		my_strcmp_op(const char *str, const char *new, int deb);
int		my_strncmp(const char *str, const char *new, const int nb);
char		*get_next_line(int fd);
char		*my_strcpy(char *str);
char		*my_strncpy(char *str, int i);
char		*my_strlcpy(char *str, int i);
char		*my_strcpy_inter(char *str, int deb, int end);
char		*my_strcat(char *str, char *way);
char		*my_strcat_separ(char *str1, char *str2, const char separator);
char		*add_char(char *str, int i, char c);
char		*decal(char *str, int i);
int		my_getnbr(const char *str);
char		*decaln(char *, int, int);

#endif /* !SHARED_H_ */
