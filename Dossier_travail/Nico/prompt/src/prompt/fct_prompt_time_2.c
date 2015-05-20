/*
** fct_prompt_time_2.c for fct_time2 in /home/parigi_n/Testrendu/PSU_2014_42sh/Nico/mysh/src/prompt
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat May 16 16:35:37 2015 Nicolas PARIGI
** Last update Sat May 16 16:35:39 2015 Nicolas PARIGI
*/

#include <time.h>
#include "my.h"

int		flag_time_month_str(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%b", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}

int		flag_time_month_nbr(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%m", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}

int		flag_time_year_first(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%y", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}

int		flag_time_year_complete(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%Y", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}
