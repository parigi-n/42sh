/*
** 42shrc.h for 42shrc in /home/vautie_a/rendu/PSU_2014_42sh/Jules/include
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 16:27:02 2015 Jules Vautier
** Last update Sun May 24 17:39:12 2015 Nicolas PARIGI
*/

#ifndef RC_H_
# define RC_H_

# define QUOTE		39

int	list_stock_rc(t_stock **, char *);
int	bashrc_alias_fct(char **);
int	bashrc_alias_parse_name(char *);
int	open_rc(t_struct *);

#endif /* !RC_H_ */
