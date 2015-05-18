/*
** my_strlen.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:21:41 2015 david sebaoun
** Last update Mon May  4 17:21:57 2015 david sebaoun
*/

int	my_strlen(char *str)
{
  int	x;

  x = 0;
  while (str && str[x] != '\0')
    x = x + 1;
  return (x);
}
