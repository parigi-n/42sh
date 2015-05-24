/*
** check_quote.c for check_quote in /home/parigi_n/Testrendu/PSU_2014_42sh/Dossier_travail/Nico/mysh/src/prompt
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Mon May 18 16:56:12 2015 Nicolas PARIGI
** Last update Mon May 18 16:56:18 2015 Nicolas PARIGI
*/

#include <stddef.h>

#define QUOTE 39
#define DQUOTE 34

int		check_quote(char *line)
{
  int		count_dqt;
  int		count_qt;
  int		i;

  i = 0;
  count_qt = 0;
  count_dqt = 0;
  if (line == NULL)
    return (-1);
  while (line[i] != '\0')
    {
      if (line[i] == DQUOTE)
	count_dqt++;
      if (line[i] == QUOTE)
	count_qt++;
      i++;
    }
  if ((count_qt % 2) != 0 || (count_dqt % 2) != 0)
    return (-1);
  return (0);
}
