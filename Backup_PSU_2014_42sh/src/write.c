/*
** test.c for test in /home/vautie_a/rendu/test
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 15:36:41 2015 Jules Vautier
** Last update Fri May 22 08:45:04 2015 Jules Vautier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static int	exe_write(int pipefd[2], int fd,
			  t_struct *var, char **tab)
{
  if (close(pipefd[0]) == -1)
    exit(puterr(ERROR_CLOSE));
  if (dup2(fd, 1) == -1)
    exit(puterr(ERROR_DUP));
  exe_solo(var, tab);
  exit(1);
  return (SUCCESS);
}

static int	write_in(int pipefd[2], int fd)
{
 int		len;
 char	buff[1024];

  if (close(pipefd[1]) == -1)
    exit(puterr(ERROR_CLOSE));
  while ((len = read(pipefd[1], buff, 1023)) > 0)
    {
      buff[len] = '\0';
      write(fd, buff, len);
    }
  return (SUCCESS);
}

int	my_write(t_struct *var, char **tab1, char **tab2)
{
  int	pid;
  int	pipefd[2];
  int	fd;

  if ((fd = open(tab2[0], O_CREAT | O_RDWR, 0664)) < 0)
    return (puterr(ERROR_OPEN));
  if (pipe(pipefd) == -1)
    return (puterr(ERROR_PIPE));
  if ((pid = fork()) == -1)
    return (puterr(ERROR_FORK));
  if (pid == 0)
    exe_write(pipefd, fd, var, tab1);
  else
    {
      if (write_in(pipefd, fd) == -1)
	return (SUCCESS);
    }
  return (SUCCESS);
}
