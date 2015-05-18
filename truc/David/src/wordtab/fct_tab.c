/*
** fct_tab.c for fct_tab in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src/wordtab
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 30 11:46:00 2015 Jules Vautier
** Last update Sun Mar 15 15:09:20 2015 Jules Vautier
*/

#include <stdlib.h>
#include "my.h"

int	my_tablen(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    i++;
  return (i);
}
