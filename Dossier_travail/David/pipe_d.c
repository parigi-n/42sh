/*
** main.c for test in /home/sebaou_d/rendu/PSU_2014_42sh/David/test
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 14 15:52:00 2015 david sebaoun
** Last update Wed May 20 16:46:01 2015 david sebaoun
*/

#include 


int	exec(int argc, char **argv)
{
  int	pipefd1[2];
  int	pipefd2[2];

  while (next != NULL)
    {
      if ((pipe(pipefd2)) == -1)
	exit(puterr("Fail with pipe\n"));  
      if ((g_pid_fils = fork()) == -1)
	exit(puterr("Fail with fork\n"));
      if (g_pid_fils = 0)
	{
	  if (prev != NULL)
	    {
	      dup2(pipefd1[0], 0);
	      close(pipefd1[0]);
	      close(pipefd1[1]);
	    }
	  if (next != NULL)
	    {
	      dup2(pipefd2[0], 0);
	      close(pipefd2[0]);
	      close(pipefd2[1]);
	    }
	  /*excec*/
	}
      else
	{
	  if (prev != NULL)
	    {
	      close(pipefd1[0]);
	      close(pipefd1[1]);
	    }
 	  if (next != NULL)
	    {
	      pipefd1[0] = pipefd2[0];
	      pipefd1[1] = pipefd2[0];
	    }
	}
    }
  if (next == NULL)
    {
      close(pipefd1[0]);
      close(pipefd1[1]);
    }
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
 }
