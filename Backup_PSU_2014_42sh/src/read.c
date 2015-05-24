/*
** read.c for read in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed May 20 16:45:14 2015 Jules Vautier
** Last update Wed May 20 17:29:43 2015 Jules Vautier
*/

#include "my.h"

char		*is_read(char **tab)
{
  int		i;
  char		*ret;

  i = 0;
  ret = NULL;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '<')
	ret = tab[i];
      i++;
    }
  return (ret);
}

int		my_read(char *str)
{

  return (SUCCESS);
}
