#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "struct.h"
#include "my.h"

#define APOSTR	39
#define RC_NAME ".tcshrc"

int             flag_s();

static const	t_prompt g_prompt[] =
  {
    {&flag_backslash, '\\'},
    {&flag_mod, '%'},
    {NULL, '\0'}
  };

int		flag_backslash()
{
  my_putchar('\\');
  return (1);
}

int		flag_mod()
{
  my_putchar('%');
  return (1);
}

int             flag_s()
{
  my_putstr("salut, s\n");
  return (0);
}

int             flag_s()
{
  my_putstr("salut, s\n");
  return (0);
}

void	freetab(char **tab);
/* Warning : La chaine générée est épurée salement. Epur même entre guillemets */

char		**my_word_to_tab_custom(char *str, char separ);
char			**my_word_to_tab_deter(char *str, char *separ);
char		*get_next_line(int fd);
static int	my_put_in_list_alias_bashrc(t_alias **alias, char **tab);
char		*epur_str(char *str);

int		flag_selector(const char *prompt_line, int i)
{
  int		t;
  int		flag_check;
  int		counter;

  counter = 0;
  flag_check = 0;
  t = 0;
  while (g_prompt[t].param != '\0')
    {
      if (prompt_line[i + 1] == g_prompt[t].param)
	{
	  flag_check = 1;
	  counter = g_prompt[t].fct_prompt() + counter;
	}
      t = t + 1;
    }
  if (flag_check == 0)
    {
      my_putchar('%');
      my_putchar(prompt_line[i + 1]);
      counter = counter + 2;
    }
  return (counter);
}

int		my_prompt(const char *prompt_line)
{
  int           i;
  int		counter;

  counter = 0;
  i = 0;
  while (prompt_line[i] != '\0')
    {
      if (prompt_line[i] == '%')
	{
	  counter = flag_selector(prompt_line, i) + counter;
	  i = i + 1;
	}
      else
	{
	  my_putchar(prompt_line[i]);
	  counter = counter + 1;
	}
      i = i + 1;
    }
  return (counter);
}

/*static int	bashrc_alias_parse_name(char **tab)
{
  int		i;
  int		check_egal;

  i = 0;
  check_egal = -1;
  while (tab[2][i] != '\0')
    {
      
      i++;
    }
  tab[2][i] = '\0';
  return (0);
}*/

static int	bashrc_alias_fct(char **tab)
{
  char		**ps1;
  int		i;

  i = 0;
  if (my_tablen(tab) > 0 && tab[0] != NULL && tab[0] != '\0')
    {
      if ((my_strcmp(tab[0], "set")) == 0)
	{
	  if (my_tablen(tab) != 4)
	    return (-1);
	  if ((my_strcmp(tab[1], "prompt")) != 0)
	    return (-1);
	  if ((my_strcmp(tab[2], "=")) != 0)
	    return (puterr("Bad syntax, no = in 'set prompt' line.\n"));
	  my_prompt(tab[3]);
	  /*my_putstr("\033[1;31m");
	  while (ps1[i] != NULL)
	    {
	      my_putchar('"');
	      my_putstr(ps1[i]);
	      my_putchar('"');
	      my_putchar('\n');
	      i++;
	    }*/
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

int		list_alias_bashrc(t_alias **alias)
{
  char		*raw_line;
  char		*line;
  char		**tab;
  int		fd;

  if ((fd = open(".tcshrc", O_RDONLY)) == -1)
    return (puterr("Error opening .rc file, (open fail)."));
  while	((raw_line = get_next_line(fd)) != NULL)
    {
      if ((line = epur_str(raw_line)) == NULL)
	puterr("Malloc error in alias epur_str.");
      if ((tab = my_word_to_tab_custom(line, '"')) == NULL)
	puterr("Line parsing failed (str_to_word_tab failed).");
      bashrc_alias_fct(tab);
      freetab(tab);
      free(line);
      free(raw_line);
    }
}

static int	my_put_in_list_alias_bashrc(t_alias **alias, char **tab)
{
  t_alias	*l_a;

  if ((l_a = malloc(sizeof(*l_a))) == NULL)
    return (puterr("Error malloc in alias list creation.\n"));
  l_a->name = my_strcpy(tab[1]);
  l_a->content = my_strcpy(tab[2]);
  if (l_a->name == NULL || l_a->content == NULL)
    return (puterr("Alias transmited to list is empty (Malloc error ?).\n"));
  l_a->next = *alias;
  *alias = l_a;
}

void		my_show_list(t_alias *list)
{
  t_alias	*tmp;

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

void            free_list(t_alias **list)
{
  t_alias        *tmp;
  t_alias        *wait;

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
  t_alias	*l_a;

  l_a = NULL;
  list_alias_bashrc(&l_a);
  my_show_list(l_a);
  free_list(&l_a);
  my_putchar('\n');
}
