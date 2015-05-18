/*
** my_show_tab.c for my_show_tab in /home/vautie_a/rendu/Piscine_C_J08/wordtab
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Oct 29 13:53:54 2014 jules vautier
** Last update Mon Apr 27 16:14:25 2015 Nicolas PARIGI
*/

#include <unistd.h>
#include <stdlib.h>

int		nb_word(char *str, int i)
{
  int		len;

  len = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] == ' ')
	i++;
      if (str[i] == '"')
	{
	  i++;
	  while (str[i] != '\0' && str[i] != '"')
	    i++;
	  if (str[i] == '"')
	    i++;
	}
      else
	{
	  while (str[i] != '\0' && str[i] != ' ' && str[i] != '"')
	    i++;
	}
      while (str[i] != '\0' && str[i] == ' ')
	i++;
      len++;
    }
  return (len);
}

int	word_len(char *str, int i)
{
  int		len;

  len = 0;
  if (str[i] == '"')
    {
      i++;
      while (str[i] != '\0' && str[i] != '"')
	{
	  i++;
	  len++;
	}
    }
  else
    {
      while (str[i] != '\0' && str[i] != ' ' && str[i] != '"')
	{
	  i++;
	  len++;
	}
    }
  return (len);
}

static char		*remp_tab(char *str, char *src, int *nb)
{
  int		i;
  int		n;

  i = *nb;
  n = 0;
  if (src[i] == '"')
    {
      i++;
      while (src[i] != '\0' && src[i] != '"')
	str[n++] = src[i++];
      i++;
    }
  else
    {
      while (src[i] != '\0' && src[i] != ' ' && src[i] != '"')
	str[n++] = src[i++];
    }
  str[n] = '\0';
  *nb = i;
  return (str);
}

char		**my_word_to_tab(char *str)
{
  char		**tab;
  int		len;
  int		i;
  int		x;

  x = 0;
  i = 0;
  if (str == NULL)
    return (NULL);
  len = nb_word(str, 0);
  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  tab[len] = NULL;
  while (str[i] != '\0')
    {
      len = word_len(str, i);
      if ((tab[x] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      tab[x] = remp_tab(tab[x], str, &i);
      if (str[i] != '\0' && str[i] != '"')
	i++;
      x++;
    }
  return (tab);
}
