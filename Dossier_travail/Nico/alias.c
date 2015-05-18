#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "struct.h"
#include "my.h"

#define APOSTR	39
#define RC_NAME ".bashrc"
void	freetab(char **tab);
/* Warning : La chaine générée est épurée salement. Epur même entre guillemets */

char		**my_word_to_tab_custom(char *str, char separ);
char		*get_next_line(int fd);
static int	my_put_in_list_stock_bashrc(t_stock **alias, char **tab);

char		*epur_str(char *str);

static int	bashrc_alias_parse_name(char **tab)
{
  int		i;
  int		check_egal;

  i = 0;
  check_egal = -1;
  while (tab[1][i] != '\0')
    {
      if (tab[1][i] == '=')
	check_egal = i;
      if (check_egal > 0 && i > check_egal)
	puterr("Wrong alias syntax (Char after [alias name]=\n");
      i++;
    }
  if (check_egal < 1)
    puterr("Wrong alias syntax (No '=' in alias name or not enough char).\n");
  tab[1][check_egal] = '\0';
  return (0);
}

static int	bashrc_alias_fct(char **tab)
{
  if (my_tablen(tab) > 0 && tab[0] != NULL && tab[0] != '\0')
    {
      if ((my_strcmp(tab[0], "alias")) == 0)
	{
	  if (my_tablen(tab) != 3)
	    puterr("Wrong Alias syntax\n");
	  if (bashrc_alias_parse_name(tab) == -1)
	    return (-1);
	}
      else
	return (-1);
    }
  else
    return (-1);
  return (0);
}

/*static	int	open_bashrc(char *home)
{
  char		*path;
  int		fd;

  if (home == NULL)
    return (puterr("Error : Home env is not set, i can't find the .rc file.\n"));
  if ((path = my_strcat_separ(home, '/', RC_NAME)) == NULL)
    return (puterr("Malloc error while creating .rc path (my_strcat).\n"));
  if ((access(path, F_OK)) == -1)
    return (puterr("Error : .rc file doesn't exist\n"));
  else
    return (puterr(".\n"));
  if ((fd = open(path, O_RDONLY)) == -1)
    puterr("Error : Open() of .rc failed.");
}*/

int		list_stock_bashrc(t_stock **alias)
{
  char		*raw_line;
  char		*line;
  char		**tab;
  int		fd;

  if ((fd = open(".bashrc", O_RDONLY)) == -1)
    return (puterr("Error opening .rc file, (open fail)."));
  while	((raw_line = get_next_line(fd)) != NULL)
    {
      if ((line = epur_str(raw_line)) == NULL)
	return (puterr("Malloc error in alias epur_str."));
      if ((tab = my_word_to_tab_custom(line, APOSTR)) == NULL)
	return (puterr("Line parsing failed (str_to_word_tab failed)."));
      if (bashrc_alias_fct(tab) == -1)
	;
      else
	{
	  if (my_put_in_list_stock_bashrc(alias, tab) == -1)
	    return (puterr("Error malloc in alias list creation.\n"));
	}
      freetab(tab);
      free(line);
      free(raw_line);
    }
}

static int	my_put_in_list_stock_bashrc(t_stock **alias, char **tab)
{
  t_stock	*l_a;

  if ((l_a = malloc(sizeof(*l_a))) == NULL)
    return (puterr("Error malloc in alias list creation.\n"));
  l_a->name = my_strcpy(tab[1]);
  l_a->content = my_strcpy(tab[2]);
  if (l_a->name == NULL || l_a->content == NULL)
    return (puterr("Alias transmited to list is empty (Malloc error ?).\n"));
  l_a->next = *alias;
  *alias = l_a;
}

int		my_put_in_list_stock(t_stock **alias, char *name, char *content)
{
  t_stock	*l_a;

  if (name == NULL || content == NULL)
    return (puterr("Error: Alias name or content are null.\n"));
  if (name[0] == '\0' || content[0] == '\0')
    return (puterr("Error: Alias name or content are null.\n"));
  if ((l_a = malloc(sizeof(*l_a))) == NULL)
    return (puterr("Error malloc in alias list creation.\n"));
  l_a->name = name;
  l_a->content = content;
  if (l_a->name == NULL || l_a->content == NULL)
    return (puterr("Alias transmited to list is empty (Malloc error ?).\n"));
  l_a->next = *alias;
  *alias = l_a;
  return (0);
}

void		my_show_list(t_stock *list)
{
  t_stock	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->name);
      my_putstr(" : ");
      my_putstr(tmp->content);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

void            free_list(t_stock **list)
{
  t_stock        *tmp;
  t_stock        *wait;

  tmp = *list;
  while (tmp != NULL)
    {
      wait = tmp->next;
      free(tmp->name);
      free(tmp->content);
      free(tmp);
      tmp = wait;
    }
}

int		main(int argc, char **argv)
{
  t_stock	*l_a;

  l_a = NULL;
  list_stock_bashrc(&l_a);
  my_show_list(l_a);
  free_list(&l_a);
}
