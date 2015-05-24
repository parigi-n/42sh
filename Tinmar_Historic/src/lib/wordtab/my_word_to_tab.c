/*
** my_show_tab.c for my_show_tab in /home/vautie_a/rendu/Piscine_C_J08/wordtab
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Oct 29 13:53:54 2014 jules vautier
** Last update Sun May 24 16:15:18 2015 Jules Vautier
*/

#include "shared.h"

static int	nb_word(char *str, int i, char *separ)
{
  int		len;
  char		c;

  len = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && char_cmp_str(str[i], separ) == 0)
	i++;
      if (str[i] == QUOTE || str[i] == DQUOTE)
	{
	  c = str[i];
	  i++;
	  while (str[i] != '\0' && str[i] != c)
	    i++;
	  len++;
	}
      else
	{
	  while (str[i] != '\0' && char_cmp_str(str[i], separ) != 0)
	    {
	      if (str[i] != '\0')
		i++;
	    }
	  len++;
	}
    }
  return (len);
}

static int	word_len(char *str,
			 int i, char *separ)
{
  int		len;
  char		c;

  len = 0;
  if (str[i] == QUOTE || str[i] == DQUOTE)
    {
      c = str[i++];
      while (str[i] != '\0' && str[i] != c)
	{
	  i++;
	  len++;
	}
    }
  else
    {
      while (str[i] != '\0' && char_cmp_str(str[i], separ) != 0
	     && str[i] != QUOTE && str[i] != DQUOTE)
	{
	  i++;
	  len++;
	}
    }
  return (len);
}

char		**my_word_to_tab(char *str, char *separ)
{
  char		**tab;
  int		len;
  int		i;
  int		x;

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
      while (str[i] != '\0' && char_cmp_str(str[i], separ) == 0)
	i++;
      len = word_len(str, i, separ);
      if ((tab[x] = my_strcpy_inter(str, i, i + len - 1)) == NULL)
	return (NULL);
      i = i + len;
      while (str[i] != '\0' && char_cmp_str(str[i], separ) == 0)
	i++;
      x++;
    }
  return (tab);
}
