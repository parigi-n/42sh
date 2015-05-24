/*
** my_show_tab.c for my_show_tab in /home/vautie_a/rendu/Piscine_C_J08/wordtab
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Oct 29 13:53:54 2014 jules vautier
** Last update Sun May 24 17:00:57 2015 Jules Vautier
*/

#include "shared.h"

static int	quote(char *str, int *i, int *len)
{
  char		c;

  c = str[*i];
  *i = *i + 1;
  while (str[*i] != '\0' && str[*i] != c)
    *i = *i + 1;
  *len = *len + 1;
  *i = *i + 1;
  return (0);
}

static int	nb_word(char *str, int i, char *separ)
{
  int		len;

  len = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (char_cmp_str(str[i], separ) == 0
				&& str[i] != QUOTE && str[i] != DQUOTE))
	i++;
      if (str[i] == QUOTE || str[i] == DQUOTE)
	quote(str, &i, &len);
      else
	{
	  while (str[i] != '\0' && char_cmp_str(str[i], separ)
		 != 0 && str[i] != QUOTE && str[i] != DQUOTE)
	    i++;
	  len++;
	}
      while (str[i] != '\0' && (char_cmp_str(str[i], separ) == 0
				&& str[i] != QUOTE && str[i] != DQUOTE))
	i++;
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

static char	**init(char *separ, char *str, int *x, int *i)
{
  int		len;
  char		**tab;

  *x = 0;
  *i = 0;
  if (str == NULL)
    return (NULL);
  len = nb_word(str, 0, separ);
  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  tab[len] = NULL;
  return (tab);
}

char		**my_word_to_tab(char *str, char *separ)
{
  char		**tab;
  int		len;
  int		i;
  int		x;

  if ((tab = init(separ, str, &x, &i)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (char_cmp_str(str[i], separ) == 0
				&& str[i] != QUOTE && str[i] != DQUOTE))
	i++;
      len = word_len(str, i, separ);
      if (str[i] == QUOTE || str[i] == DQUOTE)
	i++;
      if ((tab[x++] = my_strcpy_inter(str, i, i + len - 1)) == NULL)
	return (NULL);
      i = i + len;
      if (str[i] == QUOTE || str[i] == DQUOTE)
	i++;
      while (str[i] != '\0' && (char_cmp_str(str[i], separ) == 0
				&& str[i] != QUOTE && str[i] != DQUOTE))
	i++;
    }
  return (tab);
}
