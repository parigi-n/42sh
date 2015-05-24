/*
** alias.c for alias in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 11:09:47 2015 Jules Vautier
** Last update Sat May 23 18:49:43 2015 Jules Vautier
*/

#include "my.h"

static int	find_alias(char *str, char *alias, int *i)
{
  while (str[*i] != '\0')
    {
      if ((*i == 0) || (*i >= 1 && char_cmp_str(str[*i - 1], " |&;") == SUCCES))
	if (my_strcmp_op(str, alias, *i) == SUCCES)
	  return (0);
      *i = *i + 1;
    }
  return (-1);
}

static char	*alias_cat(char *str, char *name, char *content, int *i)
{
  char		*tmp;
  char		*new;
  char		*wait;

  if ((tmp = my_strncpy(str, *i)) == NULL)
    return (NULL);
  if ((new = decal(str, *i + my_strlen(name))) == NULL)
    return (NULL);
  if ((wait = my_strcat(content, tmp)) == NULL)
    return (NULL);
  free(tmp);
  if ((str = my_strcat(new, wait)) == NULL)
    return (NULL);
  my_printf("wtf %s\n", str);
  free(new);
  free(wait);
  *i = *i + my_strlen(name);
  return (str);
}

static char	*while_alias(char *str, t_stock **list)
{
  t_stock	*tmp;
  int		i;

  tmp = *list;
  while (tmp != NULL)
    {
      i = 0;
      while (str[i] != '\0')
	{
	  if (find_alias(str, tmp->name, &i) == SUCCES)
	    {
	      if ((str = alias_cat(str, tmp->name,
				   tmp->comment, &i)) == NULL)
		return (NULL);
	    }
	}
      tmp = tmp->next;
    }
  return (str);
}

int		remplace_alias(t_struct *var)
{
  if ((var->buff = epur_str(var->buff, 1)) == NULL)
    return (-1);
  if ((var->buff = while_alias(var->buff, &var->alias)) == NULL)
    return (ERROR);
  if ((var->buff = epur_str(var->buff, 1)) == NULL)
    return (-1);
  return (SUCCES);
}
