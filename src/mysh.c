/*
** mysh.c for mysh in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun May 24 09:34:42 2015 Jules Vautier
** Last update Sun May 24 22:57:53 2015 Jules Vautier
*/

#include <signal.h>
#include <sys/types.h>
#include "my.h"

extern int	g_pid_fils;

static int	end_mysh(t_struct *var)
{
  if (var->buff != NULL)
    free(var->buff);
  free_list_pars(&var->buffer);
  var->buffer = NULL;
  var->buff = NULL;
  g_pid_fils = 0;
  return (SUCCESS);
}

static t_buff	*exe_while(t_buff *tmp, int status)
{
  while (tmp != NULL && tmp->type == TYPE_AND && status != 0)
    tmp = tmp->next;
  while (tmp != NULL && tmp->type == TYPE_OR && status == 0)
    tmp = tmp->next;
  return (tmp);
}

static int	while_mysh(int fd, int pipefd[2],
			   t_struct *var, t_buff *tmp)
{
  if ((pipe(pipefd)) == -1)
    return (puterr("Fail with pipe\n"));
  if ((g_pid_fils = fork()) == -1)
    return (puterr("Fail with fork\n"));
  if (pipe_me(&fd, pipefd, var, tmp) == ERROR)
    return (ERROR);
  return (SUCCESS);
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
      tmp = exe_while(tmp, var->status);
      if (tmp != NULL)
	{
	  if (my_strcmp(tmp->tabl[0], "exit") == 0)
	    return (my_exit(var, tmp->tabl));
	  if ((var->status = exe_cmd(var, tmp->tabl)) != ERROR)
	    if (while_mysh(fd, pipefd, var, tmp) == ERROR)
	      return (ERROR);
	  tmp = tmp->next;
	}
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
      if ((check = parseur(var)) == 0)
	{
	  if ((check = do_mysh(var, &var->buffer)) != SUCCESS)
	    return (SUCCESS);
	}
      free(var->buff);
    }
  return (ERROR);
}
