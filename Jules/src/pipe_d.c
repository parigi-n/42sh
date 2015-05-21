/*
** main.c for test in /home/sebaou_d/rendu/PSU_2014_42sh/David/test
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 14 15:52:00 2015 david sebaoun
** Last update Thu May 21 20:04:31 2015 Jules Vautier
*/

#include "my.h"

extern int	g_pid_fils;

t_buff		*pipe_me(t_struct *var, t_buff **buffer)
{
  t_buff	*tmp;
  int		pipefd[2];
  int		fd = 0;

  tmp = *buffer;
  while (tmp != NULL)
    {
      if ((pipe(pipefd)) == -1)
	exit(puterr("Fail with pipe\n"));
      if ((g_pid_fils = fork()) == -1)
	exit(puterr("Fail with fork\n"));
      if (g_pid_fils == 0)
	{
	  dup2(fd, 0);
	  if (tmp->next != NULL)
	    dup2(pipefd[1], 1);
	  close(pipefd[0]);
	  exe_cmd(var, tmp->tab);
	  exit(-1);
	}
      else
	{
	  wait(NULL);
	  close(pipefd[1]);
	  fd = pipefd[0];
	  tmp = tmp->next;
	}
    }
  return (tmp);
}

/* for cmd in cmds */
/*     if there is a next cmd */
/* 	       pipe(new_fds) */
/*     fork */
/*     if child */
/*         if there is a previous cmd */
/* 		   dup2(old_fds[0], 0) */
/* 		   close(old_fds[0]) */
/* 		   close(old_fds[1]) */
/*         if there is a next cmd */
/* 		   close(new_fds[0]) */
/* 		   dup2(new_fds[1], 1) */
/* 		   close(new_fds[1]) */
/*         exec cmd || die */
/*      else */
/*         if there is a previous cmd */
/* 		   close(old_fds[0]) */
/* 		   close(old_fds[1]) */
/*         if there is a next cmd */
/*             old_fds = new_fds */
/* if there are multiple cmds */
/* 	   close(old_fds[0]) */
/* 	   close(old_fds[1]) 
 }*/
