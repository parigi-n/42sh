/*
** my_show_tab.c for my_show_tab in /home/vautie_a/rendu/Piscine_C_J08/wordtab
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Oct 29 13:53:54 2014 jules vautier
** Last update Sun May 17 18:34:11 2015 Jules Vautier
*/

#include "shared.h"

void	my_show_tab(char **tab)
{
  int	len;

  len = 0;
  while (tab[len] != NULL)
    {
      my_putstr(tab[len]);
      my_putchar('.');
      write(1, "\n", 1);
      len = len + 1;
    }
  my_putstr("---\n");
}
