/*
** my_putstr.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:22:11 2015 david sebaoun
** Last update Mon May  4 17:22:47 2015 david sebaoun
*/

#include <unistd.h>
#include "shared.h"

int	 my_putstr(char *str)
{
  if (str)
    write(1, str, my_strlen(str));
  return (0);
}
