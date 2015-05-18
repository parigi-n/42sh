/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
** Last update Thu Apr 30 18:17:28 2015 Martin PELLEMOINE
*/

#include <signal.h>
#include <sys/types.h>
#include "my.h"

int		g_pid_fils;

int		my_exit(t_struct *var)
{
  free_list(&var->list);
  free_list_pars(&var->buffer);
  free(var->buff);
  my_putstr("Exit the minishell.\n");
  un_raw_mod();
  return (SUCCES);
}

int		init_struct(t_struct *var, char *envp[])
{
  var->envp = envp;
  if (init_list(&var->list, var->envp) == -1)
    return (ERROR);
  g_pid_fils = 0;
  my_prompt(&var);
  /* my_printf("\033[1;36m%s \033[0m", ">$"); */
  return (SUCCES);
}

int		main(int argc, char **argv, char *envp[])
{
  t_struct	var;

  if (init_struct(&var, envp) == -1)
    return (puterr(ERROR_INIT));
  (void)argc;
  (void)argv;
  if (signal(SIGINT, gere_sig) == SIG_ERR)
    return (puterr(ERROR_SIGNAL));
  mysh(&var);
  write(1, "\n", 1);
  return (SUCCES);
}
