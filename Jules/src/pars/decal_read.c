/*
** decal_read.c for decal_read in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed May 20 17:22:34 2015 Jules Vautier
** Last update Fri May 22 18:52:35 2015 david sebaoun
*/

#include "my.h"

char		*decal_read(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == '<' && str[i + 1] == ' ') ||
	  (str[i] == '>' && str[i + 1] == ' '))
	str = decaln(str, i + 1, 1);
      if ((my_strncmp(str, "<<", 2) == SUCCES && str[i + 2] == ' ') ||
      	  (my_strncmp(str, ">>", 2) == SUCCES && str[i + 2] == ' '))
      	str = decaln(str, i + 2, 1);
      i++;
    }
  return (str);
}

/* char		*decal_read(char *str) */
/* { */
/*   int		i; */

/*   i = 0; */
/*   while (str[i] != '\0') */
/*     { */
/*       if (str[i] == '<' && str[i + 1] == ' ') */
/* 	str = decaln(str, i + 1, 1); */
/*       i++; */
/*     } */
/*   return (str); */
/* } */
