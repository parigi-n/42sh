/*
** test.c for test in /home/vautie_a/rendu/test
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 15:36:41 2015 Jules Vautier
** Last update Sun May 17 14:49:41 2015 david sebaoun
*/

#include "my.h"

extern int	g_pid_fils;

static int	do_cmd_one(t_struct *var, int pipefd[2], char **tab)
{
  if (close(pipefd[0]) == -1)
    exit(puterr(ERROR_CLOSE));
  if ((dup2(pipefd[1], 1)) == -1)
    exit(puterr(ERROR_DUP));
  exe_solo(var, tab);
  exit(0);
}

static int	do_cmd_two(t_struct *var, int pipefd[2], char **tab)
{
  if (close(pipefd[1]) == -1)
    exit(puterr(ERROR_CLOSE));
  if ((dup2(pipefd[0], 0)) == -1)
    exit(puterr(ERROR_DUP));
  exe_solo(var, tab);
  return (SUCCES);
}

static int	do_pipe(t_struct *var, char **tab1, char **tab2)
{
  int	pipefd[2];

  if ((pipe(pipefd)) == -1)
    exit(puterr(ERROR_PIPE));
  if ((g_pid_fils = fork()) == -1)
    exit(puterr(ERROR_FORK));
  if (g_pid_fils == 0)
    {
      if (do_cmd_one(var, pipefd, tab1) == -1)
	exit(-1);
    }
  else
    {
      if (do_cmd_two(var, pipefd, tab2) == -1)
	{
	  g_pid_fils = 0;
	  exit(-1);
	}
    }
  g_pid_fils = 0;
  exit(0);
  return (SUCCES);
}

int	fct_pipe(t_struct *var, char **tab1, char **tab2)
{
  int	pid;
  int	status;

  if ((pid = fork()) == -1)
    return (puterr(ERROR_FORK));
  if (pid == 0)
    do_pipe(var, tab1, tab2);
  else
    wait(&status);
  return (SUCCES);
}
