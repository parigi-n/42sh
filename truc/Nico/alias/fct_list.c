/*
** ss.c for ss.c in /home/vautie_a/rendu/CPE_2014_Pushswap/push_swap_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  8 11:30:18 2014 jules vautier
** Last update Wed Apr 29 18:01:29 2015 Jules Vautier
*/

#include "my.h"

int		init_list(t_list **envp, char **env)
{
  int		i;
  int		len;

  len = my_tablen(env);
  i = 0;
  (*envp) = NULL;
  while (i < len)
    {
      if (my_put_in_list_env(envp, env[i]) == -1)
	return (ERROR);
      i++;
    }
  if (len > 1 && (*envp = reverse_list(*envp)) == NULL)
    return (ERROR);
  return (SUCCES);
}

void		free_list(t_list **list)
{
  t_list	*tmp;
  t_list	*wait;

  tmp = *list;
  while (tmp != NULL)
    {
      wait = tmp->next;
      free(tmp->str);
      free(tmp);
      tmp = wait;
    }
}

int		my_put_in_list_env(t_list **list, char *env)
{
  t_list	*l_a;

  if ((l_a = malloc(sizeof(*l_a))) == NULL)
    {
      my_putstr("Error Malloc in put_in_list_env\n");
      return (ERROR);
    }
  if ((l_a->str = my_strcpy(env)) == NULL)
    return (ERROR);
  l_a->next = *list;
  *list = l_a;
  return (SUCCES);
}

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
