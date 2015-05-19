/*
** tabcpy.c for tabcpy in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src/wordtab
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar 12 10:07:47 2015 Jules Vautier
** Last update Sun May 17 14:57:29 2015 Jules Vautier
*/

#include "my.h"

char	**tabcpy(char **tab)
{
  char	**new;
  int		i;
  int		len;

  i = 0;
  len = my_tablen(tab);
  if ((new = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  new[len] = NULL;
  while (tab[i] != NULL)
    {
      if ((new[i] = my_strcpy(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  return (new);
}
