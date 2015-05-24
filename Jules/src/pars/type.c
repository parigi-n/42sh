/*
** parseur.c for parseur in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Mar  6 08:17:58 2015 Jules Vautier
** Last update Sun May 24 20:05:34 2015 Jules Vautier
*/

#include "my.h"

t_tabtype	g_tab[] =
  {
    {TYPE_NEW, ";"},
    {TYPE_PIPE, "|"},
    {TYPE_OR, "||"},
    {TYPE_AND, "&&"},
    {TYPE_LEFT, "<"},
    {TYPE_DLEFT, "<<"},
    {TYPE_RIGHT, ">"},
    {TYPE_DRIGHT, ">>"},
    {0, ""},
  };

static int	len_type(char *str, int i)
{
  int		len;

  len = 0;
  while (char_cmp_str(str[i], "|&;") == SUCCES)
    {
      i++;
      len++;
    }
  if (str[i] == '\0')
    return (ERROR);
  return (len);
}

static int	determin_type(char *new)
{
  int		x;

  x = 0;
  while (g_tab[x].type != 0)
    {
      if (my_strcmp(g_tab[x].str, new) == SUCCES)
	return (g_tab[x].type);
      x++;
    }
  return (0);
}

static int	creat_type(char *str, int i, int len)
{
  char		*new;
  int		x;
  int		type;

  x = 0;
  if ((new = malloc(sizeof(char) * (len + 1))) == NULL)
    return (ERROR);
  while (char_cmp_str(str[i], "|&;") == SUCCES)
    {
      new[x] = str[i];
      x++;
      i++;
    }
  new[x] = '\0';
  type = determin_type(new);
  if (type == 0)
    return (-2);
  free(new);
  return (type);
}

int		find_type(char *str, int *ptri)
{
  int		i;
  int		len;
  int		type;

  i = *ptri;
  if (str[i] == '\0')
    return (TYPE_NEW);
  if (str[i] == ';' && str[i + 1] == '\0')
    {
      *ptri = *ptri + 1;
      return (TYPE_NEW);
    }
  if ((len = len_type(str, i)) == ERROR)
    return (ERROR);
  if ((type = creat_type(str, i, len)) == -1)
    return (puterr(ERROR_MALLOC));
  i = i + len;
  *ptri = i;
  return (type);
}
