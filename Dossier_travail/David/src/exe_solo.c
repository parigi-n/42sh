/*
** test.c for test in /home/vautie_a/rendu/test
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 15:36:41 2015 Jules Vautier
** Last update Sun May 17 14:46:13 2015 david sebaoun
*/

#include "my.h"

extern int	g_pid_fils;

int		exe_solo(t_struct *var, char **tab)
{
  if (tab && tab[0] && tab[0][0] != '\0' && builtin(var, tab) == 1)
    {
      if ((g_pid_fils = fork()) == 0)
	exe_cmd(var, tab);
      else
	wait(&var->status);
      g_pid_fils = 0;
    }
  return (SUCCES);
}
