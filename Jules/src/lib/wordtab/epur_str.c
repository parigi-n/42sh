/*
** epur_str.c for epur_str in /home/vautie_a/rendu/Piscine_C_J08
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Oct 27 16:55:39 2014 jules vautier
** Last update Sat May 23 11:19:42 2015 Jules Vautier
*/

#include "shared.h"
#include "string.h"

static int	check_space(char *new, char *str,
			    int *ptri, int *ptrn)
{
  int		i;
  int		n;

  i = *ptri;
  n = *ptrn;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  if (str[i] != '\0')
    new[n++] = ' ';
  *ptri = i;
  *ptrn = n;
  return (SUCCESS);
}

static int	quote(char *new, char *str,
		      int *ptri, int *ptrn)
{
  int		i;
  int		n;

  i = *ptri;
  n = *ptrn;
  if (str[i] == 34)
    {
      new[n++] = str[i++];
      while (str[i] != '\0' && str[i] != 34)
	new[n++] = str[i++];
      if (str[i] == 34)
	new[n++] = str[i++];
    }
  *ptri = i;
  *ptrn = n;
  return (SUCCESS);
}

char	*epur_str(char *str, int check)
{
  char	*new;
  int		i;
  int		n;

  i = 0;
  n = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      quote(new, str, &i, &n);
      while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	new[n++] = str[i++];
      check_space(new, str, &i, &n);
    }
  new[n] = '\0';
  if (check == 1)
    free (str);
  return (new);
}
