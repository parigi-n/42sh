/*
** my_prompt.c for my_prompt in /home/pellem_m/PSU_2014_42sh/Tinmar/src
** 
** Made by Martin PELLEMOINE
** Login   <pellem_m@epitech.net>
** 
** Started on  Thu Apr 30 18:07:32 2015 Martin PELLEMOINE
** Last update Thu Apr 30 18:22:59 2015 Martin PELLEMOINE
*/

#include "my.h"

void		my_prompt(t_struct *var)
{
  char		*user;
  char		*prompt;

  /* if ((user = my_getenv(&var->list, "USER=")) == NULL) */
  /*     user = "Unknown User"; */
  user = my_getenv(&var->list, "USER=");
  prompt = my_strcat("$>", user);
  my_printf("\033[1;36m%s \033[0m", prompt);
}
