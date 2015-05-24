/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
** Last update Sun May 24 19:43:50 2015 Jules Vautier
*/

#include <signal.h>
#include <sys/types.h>
#include "my.h"

int		g_pid_fils;

static int	gere_flag(t_struct *var, int argc, char **argv)
{
  int		i;

  i = 1;
  while (argv[i] != NULL)
    {
      if (argc >= 2 && my_strcmp(argv[i], "-curse") == SUCCESS)
	var->term.curse = 1;
      else if (argc >= 2 && my_strcmp(argv[i], "-rc") == SUCCESS)
	var->flag_rc = 1;
      else
	printf_err("%s%s", argv[i],
		   " : Unknown flag. Please check the included man file");
      i++;
    }
  return (SUCCESS);
}

static int	init_struct(t_struct *var, int argc,
			    char **argv, char *envp[])
{
  var->env = NULL;
  var->alias = NULL;
  var->buffer = NULL;
  var->term.i = 0;
  var->term.pos = 0;
  var->term.lim_hist = 5;
  var->term.curse = 0;
  var->flag_rc = 0;
  var->term.hist = NULL;
  var->term.ret[0] = 27;
  var->term.ret[1] = 91;
  var->term.ret[2] = 68;
  var->term.ret[3] = '\0';
  if ((var->term.prompt = my_strcpy("\033[1;36m>$ \033[0m")) == NULL)
    return (ERROR);
  gere_flag(var, argc, argv);
  if (get_env(&var->env, envp) == -1)
    return (ERROR);
  if (var->flag_rc == 1)
    if ( open_rc(var) == ERROR)
      return (ERROR);
  g_pid_fils = 0;
  return (SUCCESS);
}

int		main(int argc, char **argv, char *envp[])
{
  t_struct	var;

  if (init_struct(&var, argc, argv, envp) == -1)
    return (puterr(ERROR_INIT));
  signal(SIGINT, gere_sig);
  signal(SIGQUIT, gere_sig);
  mysh(&var);
  (void)argc;
  (void)argv;
  (void)envp;
  (void)var;
  return (var.ret);
}
