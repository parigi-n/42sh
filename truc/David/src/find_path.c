/*
** find_path.c for find_path in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by root
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Jan 14 17:53:03 2015 root
** Last update Mon May 11 16:58:47 2015 Jules Vautier
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
  if ((envi = my_word_to_tab_deter(env, ": ")) == NULL)
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
