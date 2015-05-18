/*
** my_puterror.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:29:45 2015 david sebaoun
** Last update Mon May  4 17:29:47 2015 david sebaoun
*/

#include <shared.h>
#include "unistd.h"

int		puterr(char *str)
{
  if (str)
    write(2, str, my_strlen(str));
  return (ERROR);
}
