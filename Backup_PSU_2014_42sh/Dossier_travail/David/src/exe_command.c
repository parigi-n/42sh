/*
** exe_command.c for exe_cmd in /home/vautie_a/rendu/PSU_2014_minishell1
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jan 31 09:39:51 2015 Jules Vautier
** Last update Sat May 23 20:16:57 2015 Jules Vautier
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static int	init_exe_cmd(t_struct *var, char **tab)
{
  var->check = 0;
  var->exe.tmp = NULL;
  var->exe.envi = NULL;
  if ((var->exe.envtab = do_tab_exec(&var->env)) == NULL)
    return (ERROR);
  if ((var->exe.envi = do_env(&var->env)) == NULL)
    return (ERROR);
  if ((var->exe.tmp = my_strcpy(tab[0])) == NULL)
    return (ERROR);
  return (SUCCES);
}

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
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
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

static int	redir_right(int fdout, char *path)
{
  if (fdout != 0)
    close(fdout);
  if (my_strlen(path) > 2 && path[0] == '>' && path[1] == '>')
    {
      if ((fdout = open(mod_path(path, '>'),
			O_RDWR | O_APPEND | O_CREAT |
			S_IRUSR | S_IWUSR)) == ERROR)
	return (puterr("fail1\n"));
    }
  else if (my_strlen(path) > 1 && path[0] == '>')
    if ((fdout = open(mod_path(path, '>'),
		      O_RDWR | O_CREAT |
		      S_IRUSR | S_IWUSR)) == ERROR)
      return (puterr("fail2\n"));
  return (fdout);
}

static int	redir(char **tab)
{
  int		i;
  int		fdout;

  i = 0;
  fdout = 0;
  /* while (tab[i] != NULL && tab[i][0] != '>' && tab[i][0] != '<' && */
  /* 	 tab[i][my_strlen(tab[i]) - 1] != '>' && */
  /* 	 tab[i][my_strlen(tab[i]) - 1] != '>') */
  /*   ++i; */
  while (tab[i] != NULL)
    {
      my_printf("deb %s\n", tab[i]);
      if (tab[i][0] == '>' || ((tab[i][0] == '>') && (tab[i][1] == '>')))
	if ((fdout = redir_right(fdout, tab[i])) == ERROR)
	  return (ERROR);
      my_printf("end %s\n", tab[i]);
      ++i;
    }
  /* if (tab[i][0] == '<' || my_strncmp(tab[i], "<<", 2)) */
  /*   ; */
  return (SUCCES);
}

static int	do_exe_cmd(t_struct *var, int i, char **tab)
{
  int		fdout;
  char		*str;

  free(tab[0]);
  tab[0] = NULL;
  fdout = 1;
  if ((str = my_strcat(var->exe.tmp, "/")) == NULL)
    return (ERROR);
  if ((tab[0] = my_strcat(str, var->exe.envi[i])) == NULL)
    return (ERROR);
  free(str);
  if (access(tab[0], X_OK) == 0)
    {
      var->check = 1;
      if ((fdout = redir(tab)) == ERROR)
	return (ERROR);
      dup2(1, fdout);
      if (execve(tab[0], delete_redir(tab), var->exe.envtab) == ERROR)
	return (ERROR);
      close(fdout);
    }
  return (SUCCES);
}

int	exe_cmd(t_struct *var, char **tab)
{
  int	i;

  i = 0;
  if (builtin(var, tab) == SUCCES)
    exit(0);
  if ((init_exe_cmd(var, tab)) == -1)
    exit(-1);
  if (access(tab[0], X_OK) == 0)
    {
      var->check = 1;
      if (execve(tab[0], tab, var->exe.envtab) == ERROR)
	return (ERROR);
    }
  while (var->exe.envi[i] != NULL)
    {
      if (do_exe_cmd(var, i, tab) == -1)
	exit(2);
      i++;
    }
  exit(-1);
  return (ERROR);
}
