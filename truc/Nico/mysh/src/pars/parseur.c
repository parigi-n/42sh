/*
** parseur.c for parseur in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Mar  6 08:17:58 2015 Jules Vautier
** Last update Thu May 14 11:28:57 2015 Jules Vautier
*/

#include "my.h"

int		find_type(char *str)
{
  int		type;
  int		len;
  char		c;

  len = my_strlen(str);
  if (str[0] == '\0')
    return (ERROR);
  c = str[len - 1];
  if (c == ';')
    type = TYPE_NEW;
  else if (c == '>')
    type = TYPE_DROITE;
  else if (c == '<')
    type = TYPE_GAUCHE;
  else if (c == '|')
    type = TYPE_PIPE;
  else
    type = -1;
  if (type != -1)
    str[len - 1] = '\0';
  return (type);
}

static int	free_parseur(char *new, char *tmp, char **tab)
{
  free(new);
  free(tmp);
  freetab(tab);
  return (SUCCES);
}

static int	do_parseur(t_struct *var)
{
  int		i;
  int		len;
  int		type;
  char		*new;
  char		*tmp;
  char		**tab;

  i = 0;
  while (var->buff[i] != '\0')
    {
      len = parsing_len(var->buff, i);
      my_printf("len = %i\n", len);
      if ((new = malloc(sizeof(char) * (len + 2))) == NULL)
	return (puterr(ERROR_MALLOC));
      new = parsing_add(var->buff, i, new);
      if ((tmp = epur_str(new)) == NULL)
	return (ERROR);
      type = find_type(tmp);
      if ((tab = my_word_to_tab(tmp)) == NULL)
	return (puterr(ERROR_MALLOC));
      if ((my_put_in_list_pars(&var->buffer, tmp, type, tab)) == -1)
        return (puterr(ERROR_MALLOC));
      /*free_parseur(new, tmp, tab);*/
      i = advance(var->buff, i);
    }
  return (SUCCES);
}

int		parseur(t_struct *var)
{
  var->buffer = NULL;
  if (var->buff[0] == '\0')
    return (-2);
  if (remp_alias(var) == ERROR)
    return (puterr("error alias\n"));
  if ((var->buff = epur_str(var->buff)) == NULL)
    return (NULL);
  if (do_parseur(var) == -1)
    return (ERROR);
  if ((var->buffer = reverse_list_pars(var->buffer)) == NULL)
    return (puterr(ERROR_MALLOC));
  my_show_list_pars(var->buffer);
  return (SUCCES);
}
