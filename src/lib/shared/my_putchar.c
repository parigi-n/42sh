/*
** my_putchar.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun May 17 12:00:43 2015 david sebaoun
** Last update Sun May 24 17:41:11 2015 Nicolas PARIGI
*/

#include <unistd.h>
#include "shared.h"

int	my_putchar(const char c)
{
  if (write(1, &c, 1) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
