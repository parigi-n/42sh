/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
** Last update Thu Apr 30 11:16:18 2015 Jules Vautier
*/

#include <signal.h>
#include <sys/types.h>
#include "my.h"

extern int	g_pid_fils;

static int	end_mysh(t_struct *var)
{
  if (var->status == FAIL_STATUS)
    return (puterr(INVALID_CMD));
  else if (var->status != 0)
    {
      g_pid_fils = 0;
      return (puterr(ERROR_PATH));
    }
  free_list_pars(&var->buffer);
  g_pid_fils = 0;
  return (SUCCES);
}

int		do_mysh(t_struct *var, t_buff **buffer)
{
  t_buff	*tmp;
  char		**tab;

  tmp = *buffer;
  while (tmp != NULL)
    {
      tab = tmp->tab;
      if (tmp->type == 0 || tmp->type == -1)
	tmp = type_zero(var, tmp);
      else if (tmp->type == 1)
	tmp = type_one(var, tmp, tab);
      else if (tmp->type == 2)
	tmp = type_two(var, tmp, tab);
    }
  if (end_mysh(var) == -1)
    return (ERROR);
  return (SUCCES);
}

int		mysh(t_struct *var)
{
  int		check;

  while (my_get_next_str(var) == 0)
    {
      my_putchar('\n');
      if ((check = parseur(var)) == -1)
	return (puterr(INVALID_CMD));
	do_mysh(var, &var->buffer);
      free(var->buff);
      my_printf("\r\033[1;36m%s \033[0m", ">$");
    }
  return (puterr(INVALID_READ));
}
