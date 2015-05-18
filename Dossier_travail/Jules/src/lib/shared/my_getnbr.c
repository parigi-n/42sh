/*
** my_getnbr.c for lem_in in /home/sebaou_d/rendu/CPE_2014_lemin
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue Apr 21 18:07:55 2015 david sebaoun
** Last update Sun May 17 19:29:25 2015 Jules Vautier
*/

#include "shared.h"

static int	check(const char *str)
{
  int		count;
  int		i;

  i = -1;
  count = 0;
  while (str[++i] != 0)
    {
      if (str[i] > 47 && str[i] < 58)
	++count;
    }
  if (count > 10)
    return (-1);
  return (count);
}

static int	sig(int sign)
{
  if (sign == -1)
    sign = 1;
  else if (sign == 1)
    sign = -1;
  return (sign);
}

int		my_getnbr(const char *str)
{
  long	nbr;
  int	i;
  int	sign;

  i = -1;
  nbr = 0;
  sign = 1;
  if (check(str) != -1)
    {
      while (str[++i])
	{
	  if (str[i] >= '0' && str[i] <= '9')
	    nbr = (nbr * 10)  + str[i] - 48;
	  else if (nbr == 0 && str[i] == '-')
	    sign = sig(sign);
	  else
	    return (ERROR);
	}
    }
  else
    return (ERROR);
  nbr = nbr * sign;
  return (nbr);
}
