/*
** fct_tab.c for fct_tab in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src/wordtab
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 30 11:46:00 2015 Jules Vautier
** Last update Sun May 17 14:47:20 2015 Jules Vautier
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
