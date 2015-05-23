/*
** fct_prompt_time.c for fct_time in /home/parigi_n/Testrendu/PSU_2014_42sh/Nico/mysh/src/prompt
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat May 16 16:34:16 2015 Nicolas PARIGI
** Last update Sat May 16 16:34:43 2015 Nicolas PARIGI
*/

#include <time.h>
#include "my.h"

int		flag_time_hour(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%H:%M", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}

int		flag_time_hour_ampm(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%I:%M%p", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}

int		flag_time_hour_precise(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%H:%M:%S", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}

int		flag_time_day_str(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%a", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}

int		flag_time_day_nbr(t_stock **env)
{
  char		str[43];
  struct tm	*local_time;
  time_t	raw_time;

  (void)env;
  if ((raw_time = time(NULL)) == ((time_t) - 1))
    return (0);
  if ((local_time = localtime(&raw_time)) == NULL)
    return (0);
  if ((strftime(str, 42, "%d", local_time)) == 0)
    return (0);
  if (str == NULL)
    return (0);
  my_putstr(str);
  return (0);
}
