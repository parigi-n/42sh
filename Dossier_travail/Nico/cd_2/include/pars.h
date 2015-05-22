/*
** mysh.h for mysh.h in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Jan 15 09:24:53 2015 Jules Vautier
** Last update Fri May 22 09:51:45 2015 Jules Vautier
*/

#ifndef PARS_H_
# define PARS_H_

# define TAB		9
# define ERASE		127
# define UP		65
# define DOWN		66
# define RIGHT		67
# define LEFT		68
# define TYPE_NEW	1
# define TYPE_PIPE	2
# define TYPE_OR	3
# define TYPE_AND	4
# define TYPE_LEFT	5
# define TYPE_DLEFT	6
# define TYPE_RIGHT	7
# define TYPE_DRIGHT	8

typedef struct	s_tabtype
{
  int		type;
  char		*str;
}		t_tabtype;

char		*next_buff(char *, int);
char		*parsing_add(char *, int *, char *);
int		find_type(char *, int *);
int		parseur(t_struct *var);
int		remp_alias(t_struct *);
int		parsing(char *, int);
int		parsing_len(char *, int);
int		check_buff(char *);
int		eff_line(char *);
int		aff_last_line(t_struct *, char c);
int		my_get_next_str(t_struct *);
int		raw_mode(t_stock **envp);
char		*decal_read(char *);
int		prev_list_pars(t_buff **);
int		remplace_alias(t_struct *var);

#endif /* !PARS_H_ */
