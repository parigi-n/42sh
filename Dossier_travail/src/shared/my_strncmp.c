/*
** my_strncmp.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:25:30 2015 david sebaoun
** Last update Mon May  4 17:25:47 2015 david sebaoun
*/

int	my_strncmp(char *str, char *new, int nb)
{
  int	i;

  i = 0;
  while (i < (nb - 1) && str[i] != '\0' && new[i] != '\0')
    {
      if (str[i] != new[i])
	return (-1);
      i++;
    }
  if (str[i] != new[i])
    return (-1);
  return (0);
}
