/*
** my_show_tab.c for my_show_tab in /home/vautie_a/rendu/Piscine_C_J08/wordtab
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Oct 29 13:53:54 2014 jules vautier
** Last update Fri May  8 16:34:31 2015 Jules Vautier
*/

#include <unistd.h>
#include <stdlib.h>

static int		nb_word(char *str, int i, char *separ)
{
  int		len;

  len = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && char_cmp_str(str[i], separ) == 0)
	i++;
      if (char_cmp_str(str[i], separ) == 0)
	{
	  i++;
	  while (str[i] != '\0' && char_cmp_str(str[i], separ) != 0)
	    i++;
	  if (char_cmp_str(str[i], separ) == 0)
	    i++;
	}
      else
	{
	  while (str[i] != '\0' && char_cmp_str(str[i], separ) != 0)
	    i++;
	}
      while (str[i] != '\0' && char_cmp_str(str[i], separ) == 0)
	i++;
      len++;
    }
  return (len);
}

static int		word_len(char *str, int i, char *separ)
{
  int		len;

  len = 0;
  if (char_cmp_str(str[i], separ) == 0)
    {
      i++;
      while (str[i] != '\0' && char_cmp_str(str[i], separ) != 0)
	{
	  i++;
	  len++;
	}
    }
  else
    {
      while (str[i] != '\0' && char_cmp_str(str[i], separ) != 0)
	{
	  i++;
	  len++;
	}
    }
  return (len);
}

static char		*remp_tab(char *str, char *src, int *nb, char *separ)
{
  int		i;
  int		n;

  i = *nb;
  n = 0;
  if (char_cmp_str(src[i], separ) == 0)
    {
      i++;
      while (src[i] != '\0' && char_cmp_str(src[i], separ) != 0)
	str[n++] = src[i++];
      i++;
    }
  else
    {
      while (src[i] != '\0' && char_cmp_str(src[i], separ) != 0)
	str[n++] = src[i++];
    }
  str[n] = '\0';
  *nb = i;
  return (str);
}

char			**my_word_to_tab_deter(char *str, char *separ)
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
      len = word_len(str, i, separ);
      if ((tab[x] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      tab[x] = remp_tab(tab[x], str, &i, separ);
      while (str[i] != '\0' && char_cmp_str(str[i], separ) == 0)
	i++;
      x++;
    }
  return (tab);
}
