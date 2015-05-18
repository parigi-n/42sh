/*
** main.c for main.c in /home/vautie_a/rendu/Allum1/allum1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Feb  2 15:41:46 2015 Jules Vautier
** Last update Wed May  6 18:12:32 2015 Jules Vautier
*/

#include "my.h"
#include <ncurses/curses.h>
#include <term.h>

int			init_var_term(t_term *term)
{
  if ((term->go = tgetstr("cm", NULL)) == NULL)
    return (-1);
  if ((term->cl = tgetstr("cl", NULL)) == NULL)
    return (-1);
  if ((term->vi = tgetstr("vi", NULL)) == NULL)
    return (-1);
  if ((term->ve = tgetstr("ve", NULL)) == NULL)
    return (-1);
  my_printf("%s", term->cl);
  my_printf("%s", term->vi);
  return (0);
}

int                     un_raw_mod()
{
  struct termios        t;

  if (tcgetattr(0, &t) < 0)
    return (puterr("Fail tcgetattr in un_raw_mod.\n"));
  t.c_lflag = (ECHO | ICANON);
  if ((tcsetattr(0, 0, &t)) == -1)
    return (puterr("Fail tcsetattr in un_raw_mod.\n"));
  return (0);
}

int			raw_mode(t_stock **envp)
{
  struct termios	t;
  char			buff[2];
  char			*env;

  if ((env = my_getstock(envp, "TERM")) == NULL)
  return (puterr("Can't find TERM.\n"));
  tgetent(buff, env);
  if (tcgetattr(0, &t) == -1)
    return (-1);
  t.c_lflag &= ~ECHO;
  t.c_lflag &= ~ICANON;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if ((tcsetattr(0,  TCSANOW, &t)) == -1)
    return (-1);
  return (0);
}
