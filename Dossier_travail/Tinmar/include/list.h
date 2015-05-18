/*
** list.h for list.h in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb 26 17:38:14 2015 Jules Vautier
** Last update Wed Apr 29 16:49:55 2015 Jules Vautier
*/

#ifndef LIST_H_
# define LIST_H_

int     my_put_in_list_pars(t_buff **, char *, int, char **);
void    my_show_list(t_list *list);
int     init_list(t_list **envp, char **env);
void    free_list(t_list **list);
int     erase_list(t_list **list, char *str);
int     add_list_env(t_list **list, char *env, char *str);
int     listlen(t_list **list);
t_list  *reverse_list(t_list *list);
int	my_put_in_list_env(t_list **, char *env);
t_buff  *reverse_list_pars(t_buff *);
t_buff  *type_zero(t_struct *, t_buff *);
t_buff  *type_one(t_struct *, t_buff *, char **);
t_buff  *type_two(t_struct *, t_buff *, char **);
t_list  *reverse_list(t_list *);
int     my_put_in_list_env(t_list **list, char *env);
void    free_list_pars(t_buff **);

#endif /* !LIST_H_ */
