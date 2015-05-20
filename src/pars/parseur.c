/*
** parseur.c for parseur in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Mar  6 08:17:58 2015 Jules Vautier
** Last update Wed May 20 15:59:24 2015 Jules Vautier
*/

#include "my.h"

static int	free_parseur(char *new, char **tab)
{
  free(new);
  freetab(tab);
  return (SUCCES);
}

static int	do_parseur(t_struct *var, int i)
{
  int		len;
  int		type;
  char		**tab;
  char	*new;

  var->buffer = NULL;
  while (var->buff[i] != '\0')
    {
      len = parsing_len((char *)var->buff, i);
      if ((new = malloc(sizeof(char) * (len + 2))) == NULL)
	return (puterr(ERROR_MALLOC));
      new = parsing_add(var->buff, &i, new);
      if (((new = epur_str(new, 1)) == NULL) ||
	  (tab = my_word_to_tab(new, " ")) == NULL)
	return (puterr(ERROR_MALLOC));
      if ((type = find_type(var->buff, &i)) < 1)
	return (ERROR);
      if ((my_put_in_list_pars(&var->buffer,
			       new, type, tab)) == ERROR)
        return (puterr(ERROR_MALLOC));
      free_parseur(new, tab);
    }
  return (SUCCES);
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
  if (remp_alias(var) == ERROR)
    return (puterr("error alias\n"));
  if (do_parseur(var, i) == -1)
    return (ERROR);
  if ((var->buffer = reverse_list_pars(var->buffer)) == NULL)
    return (puterr(ERROR_MALLOC));
  prev_list_pars(&var->buffer)
  return (SUCCES);
}
