/*
** puterr.c for puterr in /home/vautie_a/rendu/MUL_2014_wolf3d/wolf_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Dec 31 15:55:50 2014 jules vautier
** Last update Sun May 17 15:39:15 2015 david sebaoun
*/

#include "shared.h"

int	puterr(const char *str)
{
  if (str)
    write(2, str, my_strlen(str));
  return (ERROR);
}
