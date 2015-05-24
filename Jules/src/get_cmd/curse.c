/*
** main.c for main.c in /home/vautie_a/rendu/Allum1/allum1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Feb  2 15:41:46 2015 Jules Vautier
** Last update Sun May 24 16:59:44 2015 Nicolas PARIGI
*/

#include <ncurses/curses.h>
#include <term.h>
#include "my.h"

int			init_var_term(t_term *term)
{
  if ((term->go = tgetstr("cm", NULL)) == NULL)
    return (ERROR);
  if ((term->cl = tgetstr("cl", NULL)) == NULL)
    return (ERROR);
  if ((term->vi = tgetstr("vi", NULL)) == NULL)
    return (ERROR);
  if ((term->ve = tgetstr("ve", NULL)) == NULL)
    return (ERROR);
  my_printf("%s", term->cl);
  my_printf("%s", term->vi);
  return (SUCCES);
}

int			un_raw_mod()
{
  struct termios	t;

  if (tcgetattr(0, &t) < 0)
    return (puterr("Fail tcgetattr in un_raw_mod.\n"));
  t.c_lflag = (ECHO | ICANON | ISIG);
  if ((tcsetattr(0, 0, &t)) == -1)
    return (puterr("Fail tcsetattr in un_raw_mod.\n"));
  return (SUCCES);
}

int			raw_mode(t_stock **envp)
{
  struct termios	t;
  char		buff[2];
  char		*env;

  if ((env = my_getstock(envp, "TERM")) == NULL)
    return (puterr("Can't find TERM.\n"));
  tgetent(buff, env);
  if (tcgetattr(0, &t) == -1)
    return (ERROR);
  t.c_lflag &= ~ECHO;
  t.c_lflag &= ~ICANON;
  t.c_lflag &= ~ISIG;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if ((tcsetattr(0,  TCSANOW, &t)) == -1)
    return (ERROR);
  return (SUCCES);
}
