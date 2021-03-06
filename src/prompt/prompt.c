/*
** prompt.c for prompt in /home/parigi_n/Testrendu/PSU_2014_42sh
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun May 24 23:07:05 2015 Nicolas PARIGI
** Last update Sun May 24 23:07:07 2015 Nicolas PARIGI
*/

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "my.h"

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

int	bashrc_prompt_fct(t_struct *var, char **tab)
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
	      puterr("something that is deprecated.");
	      puterr(" Please use 'set prompt = [line]'\n");
	      return (-1);
	    }
	  var->term.prompt = my_strcpy(tab[3]);
	}
      else
	return (-1);
    }
  else
    return (-1);
  return (0);
}

int		prompt_bashrc(t_struct *var, char *raw_line)
{
  char		*line;
  char		**tab;

  if ((line = epur_str(raw_line, 0)) == NULL)
    return (puterr(ERROR_MALLOC));
  if ((tab = my_word_to_tab_custom(line, '"')) == NULL)
    return (puterr(ERROR_MALLOC));
  bashrc_prompt_fct(var, tab);
  freetab(tab);
  free(line);
  return (SUCCESS);
}
