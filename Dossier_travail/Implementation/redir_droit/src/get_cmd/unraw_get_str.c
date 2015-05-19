/*
** get_str.c for get_str.c in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:24:31 2015 Jules Vautier
** Last update Sun May 17 19:08:07 2015 Jules Vautier
*/

#include "my.h"

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

static int	do_next_str(t_struct *var, char c)
{
  int		len;
  static int	check = 0;

  /*my_printf("key %i\n", c);*/
  if (c == '\n' && (check % 2) == 0)
    return (2);
  if (c == ERASE)
    {
      if ((len = my_strlen (var->buff)) > 0)
	{
	  eff_line(var->buff);
	  var->buff[len - 1] = '\0';
	}
    }
  else if ((c >= 33 || c == ' ' || c == '\t' || c == '\n'))
    var->buff = re_alloc(var->buff, c);
  if (c == '"')
    check = check + 1;
  return (SUCCES);
}

int		my_get_next_str_unraw(t_struct *var)
{
  char	c;

  if ((var->buff = malloc(1)) == NULL)
    return (-1);
  var->buff[0] = '\0';
  var->term.i = 0;
  while (read(0, &c, sizeof(c)) > 0)
    {
      if (c == 0)
	return (-1);
      if (do_next_str(var, c) != 0)
	{
	  var->term.i = 0;
	  return (SUCCES);
	}
    }
  return (ERROR);
}
