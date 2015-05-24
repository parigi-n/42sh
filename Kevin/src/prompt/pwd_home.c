/*
** pwd_home.c for pwd_home in /home/parigi_n/Testrendu/PSU_2014_42sh/Nico/mysh/src/prompt
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat May 16 17:53:49 2015 Nicolas PARIGI
** Last update Sat May 16 17:53:56 2015 Nicolas PARIGI
*/

#include <my.h>

char		*pwd_home(char *home, char *path)
{
  int		i;
  int		j;
  char		*tmp;

  i = -1;
  j = 0;
  if ((tmp = my_strcpy(path)) == NULL)
    return (NULL);
  if (my_strncmp(home, path, my_strlen(home)) == 0)
    {
      path[j++] = '~';
      i = my_strlen(home) - 1;
      while (tmp[++i] != 0)
	{
	  path[j] = tmp[i];
	  ++j;
	}
      path[j] = 0;
      return (path);
    }
  free(home);
  free(path);
  return (tmp);
}
