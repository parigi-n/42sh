/*
** fct_tab.c for fct_tab in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src/wordtab
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 30 11:46:00 2015 Jules Vautier
** Last update Thu Apr 30 12:18:25 2015 Nicolas PARIGI
*/

#include <stdlib.h>

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	freetab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  i++;
	}
    }
  if (tab != NULL)
    free(tab);
}
