/*
** mysh.h for mysh.h in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Jan 15 09:24:53 2015 Jules Vautier
** Last update Thu Apr 30 17:45:10 2015 Jules Vautier
*/

#ifndef PARS_H_
# define PARS_H_

# define TAB	9
# define ERASE	127
# define UP	65
# define DOWN	66
# define RIGHT	67
# define LEFT	68

char	*next_buff(char *, int);
char	*parsing_add(char *, int, char *);
int	find_type(char *);
int	parseur(t_struct *var);
int	parsing(char *, int);
int	parsing_len(char *, int);
int     check_buff(char *);
int	eff_line(char *);
int	aff_last_line(t_struct *, char c);
int	my_get_next_str(t_struct *);
int	raw_mode(t_list **envp);

#endif /* !PARS_H_ */
