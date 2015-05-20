/*
** my_show_tab.c for my_show_tab in /home/vautie_a/rendu/Piscine_C_J08/wordtab
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Oct 29 13:53:54 2014 jules vautier
** Last update Sun May 17 14:54:43 2015 Jules Vautier
*/

#include <unistd.h>
#include <stdlib.h>

static int		nb_word(char *str, int i, char separ)
{
  int			len;

  len = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] == ' ')
	i++;
      if (str[i] == separ)
	{
	  i++;
	  while (str[i] != '\0' && str[i] != separ)
	    i++;
	  if (str[i] == separ)
	    i++;
	}
      else
	{
	  while (str[i] != '\0' && str[i] != ' ' && str[i] != separ)
	    i++;
	}
      while (str[i] != '\0' && str[i] == ' ')
	i++;
      len++;
    }
  return (len);
}

static int		word_len(char *str, int i, char separ)
{
  int			len;

  len = 0;
  if (str[i] == separ)
    {
      i++;
      while (str[i] != '\0' && str[i] != separ)
	{
	  i++;
	  len++;
	}
    }
  else
    {
      while (str[i] != '\0' && str[i] != ' ' && str[i] != separ)
	{
	  i++;
	  len++;
	}
    }
  return (len);
}

static char	*remp_tab(char *str, char *src,
				  int *nb, char separ)
{
  int		i;
  int		n;

  i = *nb;
  n = 0;
  if (src[i] == separ)
    {
      i++;
      while (src[i] != '\0' && src[i] != separ)
	str[n++] = src[i++];
      i++;
    }
  else
    {
      while (src[i] != '\0' && src[i] != ' ' && src[i] != separ)
	str[n++] = src[i++];
    }
  str[n] = '\0';
  *nb = i;
  return (str);
}

char		**my_word_to_tab_custom(char *str,
						char separ)
{
  char		**tab;
  int			len;
  int			i;
  int			x;

  x = 0;
  i = 0;
  if (str == NULL)
    return (NULL);
  len = nb_word(str, 0, separ);
  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  tab[len] = NULL;
  while (str[i] != '\0')
    {
      len = word_len(str, i, separ);
      if ((tab[x] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      tab[x] = remp_tab(tab[x], str, &i, separ);
      if (str[i] != '\0' && str[i] != separ)
	i++;
      x++;
    }
  return (tab);
}
