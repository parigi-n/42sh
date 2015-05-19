/*
** ss.c for ss.c in /home/vautie_a/rendu/CPE_2014_Pushswap/push_swap_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  8 11:30:18 2014 jules vautier
** Last update Sun May 17 15:00:45 2015 Jules Vautier
*/

#include "my.h"

static int		len_env(char *str, int i, char c)
{
  int			len;

  len = 0;
  while (str[i] != c && str[i] != '\0')
    {
      len++;
      i++;
    }
  return (len);
}

static char	*arg_one(char *str)
{
  char		*new;
  int			x;
  int			i;

  i = 0;
  x = 0;
  if ((new = malloc(sizeof(char)
		    * (len_env(str, i, '=') + 1))) == NULL)
    return (NULL);
  while (str[i] != '=' && str[i] != '\0')
    {
      new[x] = str[i];
      x++;
      i++;
    }
  new[x] = '\0';
  return (new);
}

static char	*arg_two(char *str)
{
  char		*new;
  int			x;
  int			i;

  x = 0;
  i = len_env(str, 0, '=') + 1;
  if ((new = malloc(sizeof(char)
		    * (len_env(str, i, '\0') + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[x] = str[i];
      x++;
      i++;
    }
  new[x] = '\0';
  return (new);
}

char		**wordtab_env(char *str)
{
  char		**tab;

  if ((tab = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  tab[0] = arg_one(str);
  tab[1] = arg_two(str);
  tab[2] = NULL;
  return (tab);
}
