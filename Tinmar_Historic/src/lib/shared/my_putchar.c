/*
** my_putchar.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun May 17 12:00:43 2015 david sebaoun
** Last update Sun May 17 15:38:12 2015 david sebaoun
*/

#include <unistd.h>
#include "shared.h"

int	my_putchar(const char c)
{
  if (write(1, &c, 1) == ERROR)
    return (ERROR);
  return (OK);
}
