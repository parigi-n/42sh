/*
** my_strcpy.c for my_strcpy in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Jan 20 16:32:59 2015 Jules Vautier
** Last update Sun May 17 15:40:28 2015 david sebaoun
*/

#include "shared.h"

char	*my_strcat(char *str, char *way)
{
  char	*new;
  int		i;
  int		n;

  i = 0;
  n = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(way)
				    + my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (way[n] != '\0')
    {
      new[n] = way[n];
      n++;
    }
  while (str[i] != '\0')
    {
      new[n] = str[i];
      n++;
      i++;
    }
  new[n] = '\0';
  return (new);
}

char	*my_strcat_separ(char *str1, char *str2,
				 const char separator)
{
  char	*dest;
  int		i;
  int		a;

  i = 0;
  a = 0;
  if (str1 == NULL || str2 == NULL)
    return (NULL);
  if ((dest = malloc(sizeof(char)
		     * (my_strlen(str1) + my_strlen(str2) + 2))) == NULL)
    return (NULL);
  while (str1[a] != '\0')
    dest[i++] = str1[a++];
  dest[i++] = separator;
  a = 0;
  while (str2[a] != '\0')
    dest[i++] = str2[a++];
  dest[i] = '\0';
  return (dest);
}
