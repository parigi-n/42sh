/*
** find_path.c for find_path in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by root
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Jan 14 17:53:03 2015 root
** Last update Mon Mar  2 18:02:12 2015 Jules Vautier
*/

#include "my.h"

int	nb_env(char *env)
{
  int	i;
  int	nb;

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

char	*prepare_for_tab(char *env)
{
  int	i;
  int	j;

  i = 0;
  j = 5;
  while (env[j] != '\0')
    {
      env[i] = env[j];
      i++;
      j++;
    }
  i = 0;
  while (env[i] != '\0')
    {
      if (env[i] == ':')
	env[i] = ' ';
      i++;
    }
  return (env);
}

char	**do_env(t_list **list)
{
  char	**envi;
  char	*env;

  if ((my_getenv(list, "PATH=")) != NULL)
    if ((env = my_strcpy(my_getenv(list, "PATH="))) == NULL)
      return (NULL);
  env = prepare_for_tab(env);
  if ((envi = my_word_to_tab(env)) == NULL)
    return (NULL);
  free(env);
  return (envi);
}

char		**do_tab_exec(t_list **list)
{
  char		**tab;
  int		len;
  int		i;
  t_list	*tmp;

  tmp = *list;
  i = 0;
  len = listlen(list);
  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  tab[len] = NULL;
  while (i < len)
    {
      tab[i++] = tmp->str;
      tmp = tmp->next;
    }
  return (tab);
}
