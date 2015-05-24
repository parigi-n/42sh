/*
** exe_command.c for exe_cmd in /home/vautie_a/rendu/PSU_2014_minishell1
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jan 31 09:39:51 2015 Jules Vautier
** Last update Sun May 24 08:45:04 2015 Jules Vautier
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static char	**delete_redir(char **tab)
{
  int		i;
  char		**new_tab;

  i = 0;
  if ((new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 1))) == NULL)
    return (NULL);
  while (tab[i] != NULL && tab[i][0] != '>' && tab[i][0] != '<' &&
	 tab[i][my_strlen(tab[i]) - 1] != '>' &&
	 tab[i][my_strlen(tab[i]) - 1] != '>')
    {
      new_tab[i] = my_strcpy(tab[i]);
      ++i;
    }
  new_tab[i] = NULL;
  return (new_tab);
}

/* static int	get_flag(char *path) */
/* { */
/*   if (my_strlen(path) > 2 && path[0] == '>' && path[1] == '>') */
/*     return (O_WRONLY | O_APPEND | O_CREAT); */
/*   return (O_WRONLY | O_CREAT); */
/* } */

static char	*mod_path(char *str, char symb)
{
  int		i;
  int		j;
  char		*new_str;

  i = 0;
  j = 0;
  if ((new_str = malloc(sizeof(char)
			* (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] == symb)
    ++i;
  while (str[i] != 0)
    {
      new_str[j++] = str[i];
      ++i;
    }
  new_str[j] = 0;
  return (new_str);
}

static int	redir_right(t_struct *var, char *path)
{
  if (var->exe.fdout != 0)
    close(var->exe.fdout);
  if (my_strlen(path) > 2 && path[0] == '>' && path[1] == '>')
    {
      if ((var->exe.fdout = open(mod_path(path, '>'),
			O_RDWR | O_APPEND | O_CREAT |
			S_IRUSR | S_IWUSR)) == ERROR)
	return (puterr("fail1\n"));
    }
  else if (my_strlen(path) > 1 && path[0] == '>')
    if ((var->exe.fdout = open(mod_path(path, '>'),
			       O_RDWR | O_CREAT |
			       S_IRUSR | S_IWUSR)) == ERROR)
      return (puterr("fail2\n"));
  return (var->exe.fdout);
}

int		redir(t_struct *var, char **tab)
{
  int		i;

  i = 0;
  /* while (tab[i] != NULL && tab[i][0] != '>' && tab[i][0] != '<' && */
  /* 	 tab[i][my_strlen(tab[i]) - 1] != '>' && */
  /* 	 tab[i][my_strlen(tab[i]) - 1] != '>') */
  /*   ++i; */
  while (tab[i] != NULL)
    {
      my_printf("deb %s\n", tab[i]);
      if (tab[i][0] == '>' || ((tab[i][0] == '>') && (tab[i][1] == '>')))
	if ((var->exe.fdout =
	     redir_right(var, tab[i])) == ERROR)
	  return (ERROR);
      my_printf("end %s\n", tab[i]);
      ++i;
    }
  /* if (tab[i][0] == '<' || my_strncmp(tab[i], "<<", 2)) */
  /*   ; */
  return (SUCCES);
}
