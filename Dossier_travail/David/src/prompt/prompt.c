/*
** prompt.c for make in /home/vautie_a/rendu/PSU_2014_42sh/Dossier_travail/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed May 20 16:12:54 2015 Jules Vautier
** Last update Wed May 20 16:13:04 2015 Jules Vautier
*/

#include <stddef.h>
#include <time.h>
#include "my.h"
#include "struct.h"
#include "prompt.h"

#define APOSTR	39

static const	t_prompt g_prompt[] =
  {
    {&flag_backslash, '\\'},
    {&flag_mod, '%'},
    {&flag_name, 'n'},
    {&flag_fullhost, 'M'},
    {&flag_current_dir, '/'},
    {&flag_current_dir_home, '~'},
    {&flag_host, 'm'},
    {&flag_hist, 'h'},
    {&flag_hist, '!'},
    {&flag_escape_open, '{'},
    {&flag_escape_close, '}'},
    {&flag_time_hour_ampm, 't'},
    {&flag_time_hour, 'T'},
    {&flag_time_hour_precise, 'P'},
    {&flag_time_day_str, 'd'},
    {&flag_time_day_nbr, 'D'},
    {&flag_time_month_str, 'w'},
    {&flag_time_month_nbr, 'W'},
    {&flag_time_year_first, 'y'},
    {&flag_time_year_complete, 'Y'},
    {NULL, '\0'}
  };

static int	flag_selector(char *prompt_line, int i, t_stock **env)
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
	  counter = g_prompt[t].fct_prompt(env) + counter;
	}
      t = t + 1;
    }
  if (flag_check == 0)
    {
      my_putchar('%');
      my_putchar(prompt_line[i + 1]);
    }
  return (counter);
}

static int	backslash_special(char *prompt_line, int i, int counter)
{
  if (counter == 1 && (i + 3) <= my_strlen(prompt_line) &&
    prompt_line[i + 1] == '0' && prompt_line[i + 2] == '3'
      && prompt_line[i + 3] == '3')
    {
      my_putchar(27);
      return (3);
    }
  else if (counter == 1 && (i + 1) <= my_strlen(prompt_line)
    && prompt_line[i + 1] == 'e')
    {
      my_putchar(27);
      return (1);
    }
  else if ((i + 1) <= my_strlen(prompt_line) && prompt_line[i + 1] == 'n')
    {
      my_putchar('\n');
      return (1);
    }
  else
    my_putchar('\\');
  return (0);
}

int		my_prompt(char *prompt_line, t_stock **env)
{
  int		i;
  int		counter;

  counter = 0;
  i = 0;
  while (prompt_line[i] != '\0')
    {
      if (prompt_line[i] == '%')
	{
	  counter = flag_selector(prompt_line, i, env) + counter;
	  i = i + 2;
	}
      else
	{
	  if (prompt_line[i] == '\\')
	    i = backslash_special(prompt_line, i, counter) + i;
	  else
	    my_putchar(prompt_line[i]);
	  i++;
	}
    }
  return (0);
}

static int	bashrc_prompt_fct(char **tab, t_stock **env)
{
  if (my_tablen(tab) > 0 && tab[0] != NULL && tab[0] != '\0')
    {
      if ((my_strcmp(tab[0], "set")) == 0)
	{
	  if (my_tablen(tab) != 4)
	    return (-1);
	  if ((my_strcmp(tab[1], "prompt")) != 0)
	    return (-1);
	  if ((my_strcmp(tab[2], "=")) != 0)
	    {
	      puterr("Prompt bad syntax : no = in 'set' line. You may have used ");
	      puterr("something that is deprecated. Please use 'set prompt = [line]'\n");
	      return (-1);
	    }
	  my_prompt(tab[3], env);
	}
      else
	return (-1);
    }
  else
    return (-1);
  return (0);
}

int		prompt_bashrc(t_stock **env)
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
	return (puterr("Malloc error in alias epur_str."));
      if ((tab = my_word_to_tab_custom(line, '"')) == NULL)
	puterr("Line parsing failed (str_to_word_tab failed).");
      bashrc_prompt_fct(tab, env);
      freetab(tab);
      free(line);
      free(raw_line);
    }
  return (0);
}
