/*
** main.c for test in /home/sebaou_d/rendu/PSU_2014_42sh/David/test
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 14 15:52:00 2015 david sebaoun
** Last update Wed May 20 17:33:47 2015 david sebaoun
*/

#include "my.h"

extern int	g_pid_fils;

static int	close_fd(int fd1, int fd2)
{
  close(fd1);
  close(fd2);
  return (OK);
}

int	exec(t_buff *buff)
{
  int		pipefd1[2];
  int		pipefd2[2];
  
  while (buff->next != NULL)
    {
      if ((pipe(pipefd2)) == -1)
	exit(puterr("Fail with pipe\n"));  
      if ((g_pid_fils = fork()) == -1)
	exit(puterr("Fail with fork\n"));
      if (g_pid_fils == 0)
	{
	  if (buff->prev != NULL)
	    {
	      dup2(pipefd1[0], 0);
	      close_fd(pipefd1[0], pipefd1[1]);
	    }
	  if (buff->next != NULL)
	    {
	      dup2(pipefd2[0], 0);
	      close_fd(pipefd1[0], pipefd1[1]);
	    }
	  /*excec*/
	}
      else
	{
	  if (buff->prev != NULL)
	    close_fd(pipefd1[0], pipefd1[1]);
 	  if (buff->next != NULL)
	    {
	      pipefd1[0] = pipefd2[0];
	      pipefd1[1] = pipefd2[0];
	    }
	}
    }
  if (buff->next == NULL)
    close_fd(pipefd1[0], pipefd1[1]);
  return (OK);
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
/* 	   close(old_fds[1]) */
