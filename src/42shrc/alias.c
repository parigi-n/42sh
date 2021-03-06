/*
** init.c for alias in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/42shrc
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 16:14:28 2015 Jules Vautier
** Last update Sun Jun  7 19:31:26 2015 Nicolas PARIGI
*/

#include "my.h"

static int	rc_alias_parse_name(char *str)
{
  int		i;
  int		check_egal;

  i = 0;
  check_egal = -1;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
	check_egal = i;
      if (check_egal > 0 && i > check_egal)
	return (puterr("Wrong alias syntax (Char after [alias name]=\n"));
      i++;
    }
  if (check_egal < 1)
    {
      puterr("Wrong alias syntax (use alias foo='bar').\n");
      return (-1);
    }
  str[check_egal] = '\0';
  return (0);
}

static int	rc_alias_fct(char **tab)
{
  if (my_tablen(tab) > 0 && tab[0] != NULL && tab[0] != '\0')
    {
      if ((my_strcmp(tab[0], "alias")) == 0)
        {
          if (my_tablen(tab) != 3)
            return (puterr("Wrong Alias syntax\n"));
          if (rc_alias_parse_name(tab[1]) == -1)
            return (-1);
	  return (0);
        }
      else
	return (-1);
    }
  else
    return (-1);
  return (0);
}

int		list_stock_rc(t_stock **alias, char *raw_line)
{
  char		*line;
  char		**tab;

  if ((line = epur_str(raw_line, 0)) == NULL)
    return (puterr(ERROR_MALLOC));
  if ((tab = my_word_to_tab_custom(line, QUOTE)) == NULL)
    return (puterr(ERROR_MALLOC));
  if (rc_alias_fct(tab) != -1)
    if (add_list_stock(alias, tab[1], tab[2]) == -1)
      return (puterr(ERROR_MALLOC));
  freetab(tab);
  free(line);
  return (SUCCESS);
}
