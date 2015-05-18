/*
** my_strlen.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun May 17 12:03:26 2015 david sebaoun
** Last update Sun May 17 15:38:32 2015 david sebaoun
*/

#include <stddef.h>

int	my_strlen(const char *str)
{
  int	x;

  x = 0;
  while (str != NULL && str[x] != '\0')
    x++;
  return (x);
}
