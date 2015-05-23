/*
** get_str.c for get_str.c in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:24:31 2015 Jules Vautier
** Last update Sat May 23 16:39:23 2015 Jules Vautier
*/

#define _POSIX_SOURCE
#include <sys/types.h>
#include <signal.h>

#include "my.h"

static int	init(t_struct *var)
{
  if (raw_mode(&var->env) == ERROR)
    return (ERROR);
  if ((var->buff = malloc(1)) == NULL)
    return (ERROR);
  var->buff[0] = '\0';
  var->term.i = 0;
  return (SUCCES);
}

static char	*re_alloc(char *str, char c)
{
  char		*new;
  int			i;

  i = 0;
  if ((new = malloc(sizeof(char) *
		    (my_strlen (str) + 2))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i++] = c;
  new[i++] = '\0';
  free(str);
  return (new);
}

static int	solo_char(t_struct *var, char c)
{
  static int	check = 0;

  if (c == '\n' && (check % 2) == 0)
    {
      /*my_put_in_hist*/
      return (2);
    }
  if (c <= 31 || c == ERASE)
    gere_key_control(var, c);
  else
    {
      if ((var->buff = re_alloc(var->buff, c)) == NULL)
	return (ERROR);
    }
  eff_line(var->buff);
  my_prompt(var->term.prompt, &var->env);
  aff_last_line(var, c);
  return (SUCCES);
}

int		my_get_next_str_raw(t_struct *var)
{
  char		buff[4];
  int		len;

  if (init(var) == ERROR)
    return (ERROR);
  while ((len = read(0, buff, 3)) > 0)
    {
      buff[len] = '\0';
      if (len == 1)
	{
	  if (solo_char(var, buff[0]) == 2)
	    return (un_raw_mod());
	}
      else
	{
	  /*key_hook + hist + autocmpl*/;
	}
    }
  return (puterr(INVALID_READ));
}
