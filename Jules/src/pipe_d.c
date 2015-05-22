/*
** main.c for test in /home/sebaou_d/rendu/PSU_2014_42sh/David/test
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 14 15:52:00 2015 david sebaoun
** Last update Fri May 22 11:25:54 2015 Jules Vautier
*/

#include "my.h"

static int	son_pipe(int fd, int pipefd[2],
			 t_struct *var, t_buff *tmp)
{
  dup2(fd, 0);
  if (tmp->next != NULL && tmp->next->type == TYPE_PIPE)
    dup2(pipefd[1], 1);
  close(pipefd[0]);
  exe_cmd(var, tmp->tab);
  exit(-1);
  return (SUCCES);
}

static t_buff	*end_pipe(int *fd, int pipefd[],
			  t_struct *var, t_buff *tmp)
{
  var->status = wait(NULL);
  close(pipefd[1]);
  *fd = pipefd[0];
  return (tmp);
}

t_buff		*pipe_me(int *fd, int pipefd[2],
			 t_struct *var, t_buff *tmp)
{
  if (g_pid_fils == 0)
    son_pipe(*fd, pipefd, var, tmp);
  else
    end_pipe(fd, pipefd, var, tmp);
  return (NULL);
}
