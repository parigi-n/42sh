/*
** my_getenv.c for my_getenv in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Mar  2 16:02:58 2015 Jules Vautier
** Last update Tue Apr 28 22:05:08 2015 Jules Vautier
*/

#include "my.h"

char		*my_getenv(t_list **list, char *str)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->str != NULL && my_strncmp(tmp->str, str, my_strlen(str)) == 0)
	return (tmp->str);
      tmp = tmp->next;
    }
  return (NULL);
}
