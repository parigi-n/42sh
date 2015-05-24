/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
<<<<<<< HEAD
** Last update Sat May 23 19:25:35 2015 Jules Vautier
=======
** Last update Sat May 23 19:56:33 2015 Nicolas PARIGI
>>>>>>> b15a7a0922d9335a1cbbccab91aad0d30cc676d6
*/

#include <signal.h>
#include <sys/types.h>
#include "my.h"
#include "debug.h"

extern int	g_pid_fils;

static int	end_mysh(t_struct *var)
{
  if (var->buff != NULL)
    free(var->buff);
  free_list_pars(&var->buffer);
  var->buffer = NULL;
  var->buff = NULL;
  if (var->status == FAIL_STATUS)
    return (puterr(INVALID_CMD));
  else if (var->status != 0)
    {
      g_pid_fils = 0;
      return (ERROR);
    }
  g_pid_fils = 0;
  return (SUCCESS);
}

int		do_mysh(t_struct *var, t_buff **buffer)
{
  t_buff	*tmp;
  int		pipefd[2];
  int		fd;

  fd = 0;
  tmp = *buffer;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->tab[0], "exit") == 0)
	exit(my_exit(var, tmp->tab));
      if ((pipe(pipefd)) == -1)
	exit(puterr("Fail with pipe\n"));
      if ((g_pid_fils = fork()) == -1)
	exit(puterr("Fail with fork\n"));
      if (signal(SIGINT, gere_sig) == SIG_ERR)
	return (puterr(ERROR_SIGNAL));
      pipe_me(&fd, pipefd, var, tmp);
      my_printf("status %i\n", var->status);
      tmp = tmp->next;
    }
  if (end_mysh(var) == -1)
    return (ERROR);
  return (SUCCESS);
}

int		mysh(t_struct *var)
{
  int		check;

  while (my_get_next_str(var) == 0)
    {
      my_printf("\nstr: -%s-\n", var->buff);
      if ((check = parser(var)) == -1)
	return (puterr("fail_pars\n"));
      my_show_list_pars(var->buffer);
      do_mysh(var, &var->buffer);
      free(var->buff);
    }
  return (ERROR);
}
