/*
** main.c for test in /home/sebaou_d/rendu/PSU_2014_42sh/David/test
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 14 15:52:00 2015 david sebaoun
** Last update Sun May 24 20:42:37 2015 Jules Vautier
*/

#include "my.h"

extern int	g_pid_fils;

static int	son_pipe(int fd, int pipefd[2],
			 t_struct *var, t_buff *tmp)
{
  dup2(fd, 0);
  if (tmp->next != NULL && tmp->next->type == TYPE_PIPE)
    dup2(pipefd[1], 1);
  close(pipefd[0]);
  if (execve(tmp->tabl[0], delete_redir(tmp->tabl), var->exe.envtab) == ERROR)
    return (ERROR);
  return (SUCCES);
}

static int	end_pipe(int *fd, int pipefd[],
			  t_struct *var, t_buff *tmp)
{
  wait(&var->status);
  if (var->status == SEGFAULT)
    my_printf("Segmentation fault");
  freetab(var->exe.envtab);
  freetab(var->exe.envi);
  builtin_main(var, tmp->tabl);
  close(pipefd[1]);
  if (var->exe.fdout != 1)
    close(var->exe.fdout);
  if (var->exe.fdin != 0)
    close(var->exe.fdin);
  *fd = pipefd[0];
  return (SUCCES);
}

int		pipe_me(int *fd, int pipefd[2],
			 t_struct *var, t_buff *tmp)
{
  if (g_pid_fils == 0)
    {
      if (son_pipe(*fd, pipefd, var, tmp) == ERROR)
	return (ERROR);
    }
  else
    end_pipe(fd, pipefd, var, tmp);
  return (SUCCES);
}
