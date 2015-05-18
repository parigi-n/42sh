/*
** ss.c for ss.c in /home/vautie_a/rendu/CPE_2014_Pushswap/push_swap_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  8 11:30:18 2014 jules vautier
** Last update Sun May 17 15:35:46 2015 Jules Vautier
*/

#include "my.h"

int		get_env(t_stock **envp, char **env)
{
  int		i;
  int		len;
  char	**tab;

  len = my_tablen((char **)env);
  i = 0;
  (*envp) = NULL;
  while (i < len)
    {
      if ((tab = wordtab_env(env[i])) == NULL)
	return (puterr(ERROR_MALLOC));
      if (my_put_in_list_stock(envp, (char *)tab[0],
			       (char *)tab[1]) == -1)
	return (ERROR);
      freetab(tab);
      i++;
    }
  if (len > 1 && (*envp = reverse_list(*envp)) == NULL)
    return (ERROR);
  return (SUCCES);
}
