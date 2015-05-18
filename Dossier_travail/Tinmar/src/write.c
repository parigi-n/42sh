/*
** test.c for test in /home/vautie_a/rendu/test
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 15:36:41 2015 Jules Vautier
** Last update Sun Mar 15 17:52:54 2015 Jules Vautier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static int	exe_write(int pipefd[2], int fd,
			  t_struct *var, char **tab)
{
  if (close(pipefd[0]) == -1)
    exit(puterr("Error close\n"));
  if (dup2(fd, 1) == -1)
    exit(puterr("Error dup2\n"));
  exe_solo(var, tab);
  exit(1);
  return (SUCCES);
}

static int	write_in(int pipefd[2], int fd)
{
 int		len;
 char		buff[1024];

  if (close(pipefd[1]) == -1)
    exit(puterr("Error closee\n"));
  while ((len = read(pipefd[1], buff, 1023)) > 0)
    {
      buff[len] = '\0';
      write(fd, buff, len);
    }  return (SUCCES);
}

int	my_write(t_struct *var, char **tab1, char **tab2)
{
  int	pid;
  int	pipefd[2];
  int	fd;

  if ((fd = open(tab2[0], O_CREAT | O_RDWR, 0664)) < 0)
    return (puterr("Error Open.\n"));
  if (pipe(pipefd) == -1)
    return (puterr("Error Pipe\n"));
  if ((pid = fork()) == -1)
    return (puterr("Error Fork\n"));
  if (pid == 0)
    exe_write(pipefd, fd, var, tab1);
  else
    {
      if (write_in(pipefd, fd) == -1)
	return (SUCCES);
    }
  return (SUCCES);
}
