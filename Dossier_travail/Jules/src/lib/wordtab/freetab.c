/*
** freetab.c for  in /home/vautie_a/bin/libperso
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Oct 30 10:40:40 2014 jules vautier
** Last update Sun May 17 14:47:41 2015 Jules Vautier
*/

#include <stdlib.h>

void	freetab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
