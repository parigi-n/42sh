/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
** Last update Thu May 21 20:09:30 2015 Jules Vautier
*/

#include <signal.h>
#include <sys/types.h>
#include "my.h"
#include "debug.h"

extern int	g_pid_fils;

static int	end_mysh(t_struct *var)
{
  if (var->status == FAIL_STATUS)
    return (puterr(INVALID_CMD));
  else if (var->status != 0)
    {
      g_pid_fils = 0;
      return (ERROR);
    }
  free_list_pars(&var->buffer);
  var->buffer = NULL;
  g_pid_fils = 0;
  return (SUCCES);
}

int		do_mysh(t_struct *var, t_buff **buffer)
{
  t_buff		*tmp;

  tmp = *buffer;
  builtin(var, tmp->tab);
  pipe_me(var, buffer);
  if (end_mysh(var) == -1)
    return (ERROR);
  return (SUCCES);
}

int		mysh(t_struct *var)
{
  int		check;

  if (signal(SIGINT, gere_sig) == SIG_ERR)
    return (puterr(ERROR_SIGNAL));
  while (my_get_next_str(var) == 0)
    {
      /*my_printf("str: %s\n", var->buff);*/
      if ((check = parseur(var)) == -1)
	return (puterr("fail_pars\n"));
      /*my_show_list_pars(var->buffer);*/
      do_mysh(var, &var->buffer);
      free(var->buff);
      my_prompt(var->term.prompt, &var->env);
    }
  return (ERROR);
}
