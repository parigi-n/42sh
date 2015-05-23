/*
** alias.c for alias in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 11:09:47 2015 Jules Vautier
** Last update Sat May 23 11:09:01 2015 Jules Vautier
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
  my_printf("%s\n", str);
  if ((new = my_strcat(str, tmp)) == NULL)
    return (NULL);
  free(str);
  free(tmp);
  my_printf("%s\n", new);
  return (new);
}

static int	while_alias(t_struct *var, t_stock **list,
			    char **tab)
{
  t_stock	*tmp;
  int		i;

  tmp = *list;
  while (tmp != NULL)
    {
      i = 0;
      while (tab[i] != NULL)
	{
	  if (my_strcmp(tab[i], tmp->name) == SUCCES)
	    {
	      if ((var->buff
		   = alias_cat(tab[i], tmp->name, tmp->comment)) == NULL)
		return (ERROR);
	    }
	  i++;
	}
      tmp = tmp->next;
    }
  return (SUCCES);
}

int		remplace_alias(t_struct *var)
{
  char		**tab;

  tab = NULL;
  if ((var->buff = epur_str(var->buff, 1)) == NULL)
    return (-1);
  if ((tab = my_word_to_tab(var->buff, " ")) == NULL)
    return (puterr(ERROR_MALLOC));
  if (while_alias(var, &var->alias, tab) == ERROR)
    return (ERROR);
  freetab(tab);
  if ((var->buff = epur_str(var->buff, 1)) == NULL)
    return (-1);
  return (SUCCES);
}
