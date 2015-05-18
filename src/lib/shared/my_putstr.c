/*
** my_putstr.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun May 17 12:01:16 2015 david sebaoun
** Last update Sun May 17 15:37:00 2015 david sebaoun
*/

#include <unistd.h>
#include "shared.h"

int	 my_putstr(const char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
  return (OK);
}
