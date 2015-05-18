/*
** my_strcpy.c for my_strcpy in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Jan 20 16:32:59 2015 Jules Vautier
** Last update Mon Apr 27 17:38:18 2015 Nicolas PARIGI
*/

int		my_strcmp(char *str, char *src)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != src[i])
        return (1);
      i++;
    }
  if (str[i] != src[i])
    return (-1);
  return (0);
}

int		my_strncmp(char *str, char *src, int n)
{
  int		i;

  i = 0;
  if (my_strlen(str) < my_strlen(src))
    return (1);
  while (str[i] != '\0' && i < n)
    {
      if (str[i] != src[i])
        return (-1);
      i++;
    }
  return (0);
}

int		my_strlcmp(char *src, char *obj)
{
  int	len_src;
  int	len_obj;

  len_src = my_strlen(src);
  len_obj = my_strlen(obj);
  if (len_src < len_obj)
    return (-1);
  while (len_src >= 0 && len_obj >= 0)
    {
      if (src[len_src] != obj[len_obj])
	return (-1);
      len_src--;
      len_obj--;
    }
  return (0);
}
