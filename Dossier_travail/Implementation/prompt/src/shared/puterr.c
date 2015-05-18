/*
** puterr.c for puterr in /home/vautie_a/rendu/MUL_2014_wolf3d/wolf_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Dec 31 15:55:50 2014 jules vautier
** Last update Tue Apr 28 15:44:08 2015 Jules Vautier
*/

#include "my.h"

int		puterr(char *str)
{
  if (str)
    write(2, str, my_strlen(str));
  return (-1);
}
