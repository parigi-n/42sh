/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
** Last update Wed May 13 11:35:15 2015 Jules Vautier
*/

#include <signal.h>
#include <sys/types.h>
#include <time.h>
#include "my.h"

int		g_pid_fils;

int		init_struct(t_struct *var, char *envp[])
{
  var->env = NULL;
  var->alias = NULL;
  var->buffer = NULL;
  var->term.i = 0;
  var->envp = envp;
  if (get_env(&var->env, var->envp) == -1)
    return (ERROR);
  if (open_rc(var) == ERROR)
    return (ERROR);
  g_pid_fils = 0;
  my_printf("\033[1;36m%s \033[0m", ">$");
  return (SUCCES);
}

int		main(int argc, char **argv, char *envp[])
{
  t_struct var;
  char		*str;


  if (init_struct(&var, envp) == -1)
    return (puterr(ERROR_INIT));
  if (signal(SIGINT, gere_sig) == SIG_ERR)
    return (puterr(ERROR_SIGNAL));
  prompt_bashrc(&var.env);
    /*mysh(&var);*/
  write(1, "\n", 1);
  (void)argc;
  (void)argv;
  (void)envp;
  (void)var;
  return (SUCCES);
}
