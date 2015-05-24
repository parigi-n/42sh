/*
** my_str_gather.c for str_gather in /home/parigi_n/testc
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Mon Jan 26 12:02:13 2015 Nicolas PARIGI
** Last update Fri Jan 30 17:08:13 2015 Nicolas PARIGI
*/

#include <stdlib.h>

char	*my_strcat_separ(char *str1, char *str2, char separator)
{
  char	*dest;
  int	i;
  int	a;

  i = 0;
  a = 0;
  if ((dest = malloc(sizeof(char)
		     * (my_strlen(str1) + my_strlen(str2) + 2))) == NULL)
    return (NULL);
  if (str1 != NULL)
    {
      while (a < my_strlen(str1))
	dest[i++] = str1[a++];
    }
  dest[i++] = separator;
  if (str2 != NULL)
    {
      a = 0;
      while (a < my_strlen(str2))
	dest[i++] = str2[a++];
    }
  dest[i] = '\0';
  return (dest);
}
