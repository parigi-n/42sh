/*
** my.h for my.h in /home/vautie_a/rendu/PSU_2014_my_printf/printf
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Nov  7 17:58:33 2014 jules vautier
** Last update Wed May 13 15:04:42 2015 Jules Vautier
*/

#ifndef PRINTF_H_
# define PRINTF_H_

# include <stdarg.h>

typedef struct	s_flag
{
  int		(*ptr)(int i, va_list ap);
  char		flag;
}		t_flag;

typedef struct	s_counter
{
  int		i;
  int		len;
}		t_counter;

int	my_printf(char *arg, ...);
int	printf_error(char *arg, ...);
int	aff_print_c(int len, va_list ap);
int	aff_print_s(int len, va_list ap);
int	aff_print_d(int len, va_list ap);
int	aff_print_t(int len, va_list ap);
int	aff_print_mod(int len, va_list ap);

#endif /* !PRINTF_H_ */
