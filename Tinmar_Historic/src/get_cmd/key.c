/*
** fct_spec.c for fct_spec in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Apr 30 12:11:26 2015 Jules Vautier
** Last update Sun May 24 20:49:48 2015 Martin PELLEMOINE
*/

#include "my.h"
#include "string.h"

int		gere_up(t_struct *var)
{
  var->term.pos = var->term.pos + 1;
  var->term.pos = var->term.pos % var->term.lim_hist;
  if (var->buff == NULL)
      return (ERROR);
  if ((var->buff = my_strcpy(var->term.hist->str)) == NULL)
    return (ERROR);
  my_putstr(var->term.hist->str);
  return (SUCCES);
}

int		gere_down(t_struct *var)
{
  var->term.pos = var->term.pos - 1;
  var->term.pos = var->term.pos % var->term.lim_hist;
  return (SUCCES);
}

int		gere_right(t_struct *var, char *str)
{
  if (var->term.i < my_strlen (var->buff))
    {
      my_putstr(str);
      var->term.i = var->term.i + 1;
    }
  return (SUCCES);
}

int		gere_left(t_struct *var, char *str)
{
  if (var->term.i > 0)
    {
      var->term.i = var->term.i - 1;
      my_putstr(str);
    }
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
