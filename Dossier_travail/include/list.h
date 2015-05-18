/*
** list.h for list.h in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb 26 17:38:14 2015 Jules Vautier
** Last update Fri Mar  6 16:10:50 2015 Jules Vautier
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  char		*str;
  struct s_list	*next;
}		t_list;

typedef struct	s_buff
{
  char		*buff;
  char		**tab;
  int		type;
  struct s_buff	*next;
}		t_buff;

int	init_list(t_list **, char **);
void	free_list(t_list **);
int	my_put_in_list_env(t_list **, char *env);
void	my_show_list(t_list *list);

#endif /* !LIST_H_ */
