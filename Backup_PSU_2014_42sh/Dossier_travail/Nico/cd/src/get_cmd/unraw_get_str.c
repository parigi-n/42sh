/*
** get_str.c for get_str.c in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:24:31 2015 Jules Vautier
** Last update Wed May 20 18:38:39 2015 Jules Vautier
*/

#include "my.h"

int		my_get_next_str_unraw(t_struct *var)
{
  var->term.i = 0;
  var->buff = get_next_line(0);
  if (var->buff == NULL)
    return (ERROR);
  return (SUCCES);
}
