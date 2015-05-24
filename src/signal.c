/*
** signal.c for signal in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 26 18:11:37 2015 Jules Vautier
** Last update Sun May 24 21:38:24 2015 Nicolas PARIGI
*/

#define _POSIX_SOURCE
#include <sys/types.h>
#include <signal.h>
#include "my.h"

extern int	g_pid_fils;

void		gere_sig(int sign)
{
  my_printf("Ctrl-C %i\n");
  if ((sign == SIGINT || sign == SIGQUIT) && g_pid_fils != 0)
    {
      if (kill(g_pid_fils, SIGKILL) == -1 )
	puterr(ERROR_KILL);
    }
  else if (g_pid_fils == 0 && sign == SIGQUIT)
    kill(SIGSTOP, 0);
  my_printf("\n\033[1;36m%s \033[0m", ">$");
  g_pid_fils = 0;
  signal(sign, gere_sig);
}
