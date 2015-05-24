/*
** mysh.c for mysh in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun May 24 09:34:42 2015 Jules Vautier
** Last update Sun May 24 10:43:53 2015 Jules Vautier
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
  return (SUCCES);
}

static t_buff	*exe_mysh(t_struct *var, t_buff *tmp)
{
  int		pipefd[2];
  int		fd;

  fd = 0;
  if (tmp != NULL)
    {
      if (my_strcmp(tmp->tab[0], "exit") == 0)
	exit(my_exit(var, tmp->tab));
      if ((pipe(pipefd)) == -1)
	exit(puterr("Fail with pipe\n"));
      if ((g_pid_fils = fork()) == -1)
	exit(puterr("Fail with fork\n"));
      if (signal(SIGINT, gere_sig) == SIG_ERR)
	exit(puterr(ERROR_SIGNAL));
      pipe_me(&fd, pipefd, var, tmp);
      tmp = tmp->next;
    }
  return (tmp);
}

static int	do_mysh(t_struct *var, t_buff **buffer)
{
  t_buff	*tmp;
  int		pipefd[2];
  int		fd;

  fd = 0;

  tmp = *buffer;
  while (tmp != NULL)
    {
      my_printf("tmp %s\n", tmp->buff);
      if (my_strcmp(tmp->tab[0], "exit") == 0)
	exit(my_exit(var, tmp->tab));
      if ((pipe(pipefd)) == -1)
	exit(puterr("Fail with pipe\n"));
      if ((g_pid_fils = fork()) == -1)
	exit(puterr("Fail with fork\n"));
      if (signal(SIGINT, gere_sig) == SIG_ERR)
	exit(puterr(ERROR_SIGNAL));
      pipe_me(&fd, pipefd, var, tmp);
      tmp = tmp->next;
      /*while (tmp != NULL && tmp->type == TYPE_AND && var->status != 0)
	tmp = tmp->next;
      while (tmp != NULL && tmp->type == TYPE_OR && var->status == 0)
      tmp = tmp->next;*/
      /*tmp = exe_mysh(var, tmp);*/
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
      my_printf("\nstr: -%s-\n", var->buff);
      if ((check = parseur(var)) == 0)
	{
	  my_show_list_pars(var->buffer);
	  do_mysh(var, &var->buffer);
	}
      free(var->buff);
      if (check == -1)
	return (ERROR);
    }
  return (ERROR);
}
