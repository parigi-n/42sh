/*
** get_next_line.c for get_next_line in /home/parigi_n/testc/get_next_line
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Jan 13 16:21:45 2015 Nicolas PARIGI
** Last update Tue Mar 31 16:20:46 2015 Jules Vautier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_re_alloc(char *str)
{
  char		*str_re_alloc;
  int		i;

  i = 0;
  if ((str_re_alloc = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      str_re_alloc[i] = str[i];
      i = i + 1;
    }
  str_re_alloc[i + 1] = '\0';
  free(str);
  return (str_re_alloc);
}

char		*get_next_line(int fd)
{
   char		*line_str;
   static char	buffer[BUFFER_SIZE];
   int		size;
   int		i;

   size = 0;
   i = 0;
   if ((line_str = malloc(sizeof(char))) == NULL)
     return (NULL);
   line_str[0] = '\0';
   while ((size = read(fd, buffer, BUFFER_SIZE)) > 0 && buffer[0] != '\n')
     {
       if ((line_str = my_re_alloc(line_str)) == NULL)
	 return (NULL);
       line_str[i] = buffer[0];
       i = i + 1;
     }
   if (i == 0 && size == 0)
     {
       if (line_str != NULL)
	 free(line_str);
       return (NULL);
     }
   return (line_str);
}
