/*
** find_path.c for find_path in /home/parigi_n/Testrendu/PSU_2014_42sh/src
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Jun  7 19:26:14 2015 Nicolas PARIGI
** Last update Sun Jun  7 19:26:20 2015 Nicolas PARIGI
*/

#include "my.h"

int		nb_env(char *env)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while (env[i] != '\0')
    {
      if (env[i] == ':')
	nb++;
      i++;
    }
  return (nb + 1);
}

char		**do_env(t_stock **list)
{
  char		**envi;
  char		*env;
  char		*res;

  if ((res = (my_getstock(list, "PATH"))) != NULL)
    if ((env = my_strcpy(res)) == NULL)
      {
	puterr(ERROR_PATH);
	return (NULL);
      }
  if ((envi = my_word_to_tab(env, ": ")) == NULL)
    return (NULL);
  free(env);
  return (envi);
}

char		**do_tab_exec(t_stock **list)
{
  char		**tab;
  int		len;
  int		i;
  t_stock	*tmp;

  tmp = *list;
  i = 0;
  len = listlen(list);
  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  while (i < len)
    {
      if ((tab[i++] = my_strcat_separ(tmp->name, tmp->comment, '=')) == NULL)
	return (NULL);
      tmp = tmp->next;
    }
  tab[i] = NULL;
  return (tab);
}
