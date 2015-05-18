/*
** my_putchar.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:24:02 2015 david sebaoun
** Last update Mon May  4 17:24:11 2015 david sebaoun
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
