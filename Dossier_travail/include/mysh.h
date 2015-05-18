/*
** mysh.h for mysh.h in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Jan 15 09:24:53 2015 Jules Vautier
** Last update Fri May 15 11:52:21 2015 david sebaoun
*/

#ifndef MYSH_H_
# define MYSH_H_

# include "list.h"
# define FAIL_STATUS	65280

typedef struct	s_struct
{
  int		check;
  int		pid;
  int		len;
  int		status;
  char		*new;
  char		*buff;
  char		**tab;
  char		**envi;
  char		**envp;
  char		**envtab;
  t_list	*list;
  t_buff	*buffer;
}		t_struct;

int	mysh(char **);
int	exe_cmd(t_struct *var, char **tab);
char	**do_cmd(char *, char **);
char	*my_getenv(t_list **, char *);
char	*get_next_line(int);
char	*prepare_for_tab(char *);
char	**do_env(t_list **);
void	gere_sig();
int	my_get_envp(t_struct *, char **);
int	my_unsetenv(t_struct *);
char	**my_cpy_tab(char **, char **, int);
int	builtin(t_struct *, char **);
int	my_cd(t_struct *, char **);
int	my_setenv(t_struct *);
int	my_check_setenv(t_struct *);
int	find_old_setenv(t_struct *);
int	my_exit(t_struct *var);
int	init_struct(t_struct *, char *envp[]);
char	**do_tab_exec(t_list **);
char	*next_buff(char *, int);
char	*parsing_add(char *, int, char *);
int	find_type(char *);
int	my_put_in_list_pars(t_buff **, char *, int, char **);
int     my_write(t_struct *var, char **tab1, char **tab2);
int	parseur(t_struct *var);
int	exe_solo(t_struct *, char **);
int	check_buff(char *);
int	parsing(char *, int);
int	parsing_len(char *, int);
int	fct_pipe(t_struct *var, char **, char **);

#endif /* !MYSH_H_ */
