/*
** parseur.c for parseur in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Mar  6 08:17:58 2015 Jules Vautier
** Last update Sun Jun  7 19:12:40 2015 Nicolas PARIGI
*/

#include "my.h"

static int	free_parseur(char *new, char **tab)
{
  free(new);
  freetab(tab);
  return (SUCCESS);
}

static char	**mod_tab(char **tab)
{
  int		i;
  int		j;
  char		**new_tab;

  i = -1;
  j = 0;
  if ((new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 1))) == NULL)
    return (NULL);
  while (tab[++i] != NULL)
    {
      if (tab[i][0] != '<' && tab[i][0] != '>' &&
	  (tab[i][0] != '>' || tab[i][1] != '>') &&
	  (tab[i][0] != '<' || tab[i][1] != '<'))
	new_tab[j++] = my_strcpy(tab[i]);
    }
  i = -1;
  while (tab[++i] != NULL)
    {
      if (tab[i][0] == '<' || tab[i][0] == '>' || (tab[i][0] == '>'
						   && tab[i][1] == '>') || (tab[i][0] == '<' && tab[i][1] == '<'))
	new_tab[j++] = my_strcpy(tab[i]);
    }
  new_tab[j] = NULL;
  freetab(tab);
  return (new_tab);
}

static int	do_parseur(t_struct *var, int i)
{
  int		len;
  int		type;
  char		**tab;
  char		*new;

  var->buffer = NULL;
  type = TYPE_NEW;
  while (var->buff[i] != '\0')
    {
      len = parsing_len((char *)var->buff, i);
      if ((new = malloc(sizeof(char) * (len + 2))) == NULL)
	return (puterr(ERROR_MALLOC));
      new = parsing_add(var->buff, &i, new);
      if (((new = epur_str(new, 1)) == NULL) ||
	  (new = decal_read(new)) == NULL ||
	  (tab = mod_tab(my_word_to_tab(new, " "))) == NULL)
	return (puterr(ERROR_MALLOC));
      if ((my_put_in_list_pars(&var->buffer,
			       new, type, tab)) == ERROR)
        return (puterr(ERROR_MALLOC));
      if ((type = find_type(var->buff, &i)) < 1)
	return (ERROR);
      free_parseur(new, tab);
    }
  return (SUCCESS);
}

int		parseur(t_struct *var)
{
  int		i;

  i = 0;
  var->buffer = NULL;
  if ((var->buff = epur_str(var->buff, 1)) == NULL)
    return (ERROR);
  if (var->buff[0] == '\0')
    return (-2);
  if (remplace_alias(var) == ERROR)
    return (-2);
  if (do_parseur(var, i) == -1)
    {
      printf_err(INVALID_SYNTAX, var->buff);
      return (-2);
    }
  if ((var->buffer = reverse_list_pars(var->buffer)) == NULL)
    return (puterr(ERROR_MALLOC));
  prev_list_pars(&var->buffer);
  return (SUCCESS);
}
