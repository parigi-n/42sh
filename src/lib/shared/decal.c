/*
** decal.c for decal in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/shared
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri May  8 09:09:43 2015 Jules Vautier
** Last update Sun May 24 18:49:20 2015 Jules Vautier
*/

#include	"my.h"

char		*decal(char *str, int i)
{
  int		x;

  x = 0;
  if (i > my_strlen(str))
    return (NULL);
  while (str[i] != '\0')
    {
      str[x] = str[i];
      x++;
      i++;
    }
  str[x] = '\0';
  return (str);
}

char		*decaln(char *str, int deb, int len)
{
  int		x;
  int		i;

  i = deb + len;
  x = deb;
  if (i > my_strlen(str))
    return (str);
  while (str[i] != '\0')
    {
      str[x] = str[i];
      x++;
      i++;
    }
  str[x] = '\0';
  return (str);
}
