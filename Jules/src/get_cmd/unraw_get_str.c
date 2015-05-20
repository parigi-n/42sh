/*
** get_str.c for get_str.c in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:24:31 2015 Jules Vautier
** Last update Mon May 18 17:06:44 2015 Jules Vautier
*/

#include "my.h"

int		my_get_next_str_unraw(t_struct *var)
{
  char		buff[1024];
  int		len;

  if ((var->buff = malloc(1)) == NULL)
    return (-1);
  var->buff[0] = '\0';
  var->term.i = 0;
  while ((len = read(0, buff, 1023)) > 0)
    {
      if (buff[0] != '\0' && len > 0)
	buff[len - 1] = '\0';
      if ((var->buff = my_strcpy(buff)) == NULL)
	return (ERROR);
      my_strlen(var->buff);
      return(SUCCES);
    }
  return (ERROR);
}
