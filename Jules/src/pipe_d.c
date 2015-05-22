/*
** main.c for test in /home/sebaou_d/rendu/PSU_2014_42sh/David/test
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 14 15:52:00 2015 david sebaoun
** Last update Fri May 22 08:59:23 2015 Jules Vautier
*/

#include "my.h"

extern int	g_pid_fils;

static int	son_pipe(int fd, int pipefd[2],
			 t_struct *var, t_buff *tmp)
{
  dup2(fd, 0);
  if (tmp->next != NULL)
    dup2(pipefd[1], 1);
  close(pipefd[0]);
  exe_cmd(var, tmp->tab);
  exit(-1);
  return (SUCCES);
}

static t_buff	*end_pipe(int *fd, int pipefd[],
			  t_buff *tmp)
{
  wait(NULL);
  close(pipefd[1]);
  *fd = pipefd[0];
  tmp = tmp->next;
  return (tmp);
}

t_buff		*pipe_me(t_struct *var, t_buff **buffer)
{
  t_buff	*tmp;
  int		pipefd[2];
  int		fd = 0;

  tmp = *buffer;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->tab[0], "exit") == 0)
	exit(my_exit(var, tmp->tab));
      if ((pipe(pipefd)) == -1)
	exit(puterr("Fail with pipe\n"));
      if ((g_pid_fils = fork()) == -1)
	exit(puterr("Fail with fork\n"));
      if (g_pid_fils == 0)
	son_pipe(fd, pipefd, var, tmp);
      else
	tmp = end_pipe(&fd, pipefd, tmp);
    }
  return (tmp);
}
