/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
<<<<<<< HEAD
** Last update Sun May 24 11:46:51 2015 Jules Vautier
=======
** Last update Sat May 23 19:33:26 2015 Martin PELLEMOINE
>>>>>>> dfc23cc18e4b7f40ea8a9f36cc395ba2a4fc9079
*/

#include <signal.h>
#include <sys/types.h>
#include "my.h"

int		g_pid_fils;

static int	gere_flag(t_struct *var, int argc, char **argv)
{
  int		i;

  i = 0;
  while (argv[i] != NULL)
    {
      if (argc >= 2 && my_strcmp(argv[i], "-curse") == SUCCES)
	var->term.curse = 1;
      else if (argc >= 2 && my_strcmp(argv[i], "-rc") == SUCCES)
	var->flag_rc = 1;
      i++;
    }
  return (SUCCES);
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
  if ((var->term.prompt = my_strcpy("$>")) == NULL)
    return (ERROR);
  gere_flag(var, argc, argv);
  if (get_env(&var->env, envp) == -1)
    return (ERROR);
  if (var->flag_rc == 1)
    if ( open_rc(var) == ERROR)
      return (ERROR);
  g_pid_fils = 0;
  return (SUCCES);
}

int		main(int argc, char **argv, char *envp[])
{
  t_struct	var;

  if (init_struct(&var, argc, argv, envp) == -1)
    return (puterr(ERROR_INIT));
  signal(SIGINT, gere_sig);
  signal(SIGQUIT, gere_sig);
  mysh(&var);
  write(1, "\n", 1);
  (void)argc;
  (void)argv;
  (void)envp;
  (void)var;
  return (SUCCES);
}