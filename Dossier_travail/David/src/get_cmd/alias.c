/*
** alias.c for alias in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 11:09:47 2015 Jules Vautier
** Last update Thu May 14 16:39:10 2015 Jules Vautier
*/

#include "my.h"

static int	find_alias(char *str, char *alias)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (my_strcmp_op(str, alias, i) == SUCCES)
	return (i);
      i++;
    }
  return (-1);
}

static char	*alias_cat(char *str, char *alias, char *content)
{
  int		i;
  char		*tmp;
  char		*new;

  if ((i = find_alias(str, alias)) == ERROR)
    return (NULL);
  if ((new = my_strncpy(str, i)) == NULL)
    return (NULL);
  if ((tmp = my_strcat(content, new)) == NULL)
    return (NULL);
  free(new);
  if ((str = my_strlcpy(str, i + my_strlen(alias))) == NULL)
    return (NULL);
  if ((new = my_strcat(str, tmp)) == NULL)
    return (NULL);
  free(str);
  free(tmp);
  return (new);
}

static int	while_alias(t_struct *var, char **tab,
			    int check)
{
  char		*alias;
  int		i;

  i = 0;
  while (tab[i] != NULL && check == 0)
    {
      if ((alias = my_getstock(&var->alias, tab[i])) != NULL)
	{
	  check = 1;
	  if ((var->buff = (alias_cat(var->buff,
				      tab[i], alias))) == NULL)
	    return (puterr(ERROR_MALLOC));
	}
      i++;
    }
  return (check);
}

int		remp_alias(t_struct *var)
{
  char		**tab;
  int		check;

  tab = NULL;
  check = 1;
  while (check == 1)
    {
      check = 0;
      if ((tab = my_word_to_tab(var->buff)) == NULL)
	return (puterr(ERROR_MALLOC));
      check = while_alias(var, tab, check);
      freetab(tab);
    }
  return (SUCCES);
}
