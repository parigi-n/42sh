/*
** mysh.h for mysh.h in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Jan 15 09:24:53 2015 Jules Vautier
** Last update Sun May 24 17:10:12 2015 Jules Vautier
*/

#ifndef GETCMD_H_
# define GETCMD_H_

int	my_get_next_str_raw(t_struct *var);
int	my_get_next_str_unraw(t_struct *var);
int	my_get_next_str(t_struct *var);
int	un_raw_mod();
int	end_get_cmd(t_struct *);
int	key_hook(t_struct *, char *);
int	gere_left(t_struct *, char *);
int	gere_right(t_struct *, char *);
int	gere_up(t_struct *);
int	gere_down(t_struct *);

#endif /* !GETCMD_H_ */
