/*
** list.h for list.h in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb 26 17:38:14 2015 Jules Vautier
** Last update Fri May 22 19:20:55 2015 Martin PELLEMOINE
*/

#ifndef LIST_H_
# define LIST_H_

int	my_put_in_list_pars(t_buff **, char *, int, char **);
void	my_show_list(t_stock *list);
int	get_env(t_stock **envp, char **env);
void	free_list(t_stock **list);
int	erase_list(t_stock **list, char *str);
int	add_list_stock(t_stock **list, char *env, char *str);
int	listlen(t_stock **list);
t_stock	 *reverse_list(t_stock *list);
int	my_put_in_list_stock(t_stock **, char *, char *);
t_buff	*reverse_list_pars(t_buff *);
t_stock	*reverse_list(t_stock *);
void	free_list_pars(t_buff **);
void	my_show_list(t_stock *);
void	my_show_list_pars(t_buff *);
void    free_hist(t_hist **hist);
int	my_put_in_hist(t_hist **hist, char *cmd);
void	my_show_hist(t_hist **hist_stock);

#endif /* !LIST_H_ */
