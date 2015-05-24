/*
** fct_spec.c for fct_spec in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Apr 30 12:11:26 2015 Jules Vautier
** Last update Sat May 23 16:39:54 2015 Jules Vautier
*/

#include "my.h"
#include "string.h"

int		gere_up(t_struct *var)
{
  /*if (var->term.hist < onche)*/
    var->term.hist = var->term.hist - 1;
  return (SUCCES);
}

int		gere_down(t_struct *var)
{
  if (var->term.hist > 0)
    var->term.hist = var->term.hist - 1;
  return (SUCCES);
}

int		gere_right(t_struct *var)
{
  if (var->term.i < my_strlen (var->buff))
    var->term.i = var->term.i + 1;
  return (SUCCES);
}

int		gere_left(t_struct *var)
{
  if (var->term.i > 0)
    var->term.i = var->term.i - 1;
  return (SUCCES);
}

int		gere_key_control(t_struct *var, char c)
{
  int		len;

  if (c == 3)
    {
      my_putchar('\n');
      my_prompt(var->term.prompt, &var->env);
      eff_line(var->buff);
    }
  else if (c == ERASE)
    {
      if ((len = my_strlen(var->buff)) > 0)
        var->buff[len - 1] = '\0';
    }
  return (SUCCES);
}
