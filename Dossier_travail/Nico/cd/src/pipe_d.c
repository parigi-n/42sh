/*
** main.c for test in /home/sebaou_d/rendu/PSU_2014_42sh/David/test
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 14 15:52:00 2015 david sebaoun
** Last update Thu May 21 15:14:33 2015 Jules Vautier
*/

#include "my.h"

extern int	g_pid_fils;

t_buff	*pipe_me(t_struct *var, t_buff **buffer)
{
  t_buff	*tmp;
  int	pipefd1[2];
  int	pipefd2[2];

  tmp = *buffer;
  while (tmp != NULL)
    {
      if ((pipe(pipefd2)) == -1)
	exit(puterr("Fail with pipe\n"));
      if ((g_pid_fils = fork()) == -1)
	exit(puterr("Fail with fork\n"));
      if (g_pid_fils == 0)
	{
	  if (tmp->prev != NULL)
	    {
	      dup2(pipefd1[0], 0);
	      close(pipefd1[0]);
	      close(pipefd1[1]);
	    }
	  if (tmp->next != NULL)
	    {
	      dup2(pipefd2[0], 0);
	      close(pipefd2[0]);
	      close(pipefd2[1]);
	    }
	  /*if (builtin(var, tmp->tab) == -1)*/
	    exe_cmd(var, tmp->tab);
	}
      else
	{
	  if (tmp->prev != NULL)
	    {
	      close(pipefd1[0]);
	      close(pipefd1[1]);
	    }
 	  if (tmp->next != NULL)
	    {
	      pipefd1[0] = pipefd2[0];
	      pipefd1[1] = pipefd2[0];
	    }
	}
      tmp = tmp->next;
    }
  /*if (tmp->next == NULL)
    {
      close(pipefd1[0]);
      close(pipefd1[1]);
      }*/
      close(pipefd1[0]);
      close(pipefd1[1]);
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
