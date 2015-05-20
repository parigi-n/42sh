/*
** mysh.h for mysh.h in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Jan 15 09:24:53 2015 Jules Vautier
** Last update Wed May 20 17:14:36 2015 david sebaoun
*/

#ifndef MYSH_H_
# define MYSH_H_

# define FAIL_STATUS	65280
# define RC_NAME	".bashrc"
# define QUOTE		39

int	exec(t_buff *buff);
int	my_get_next_str_raw(t_struct *var);
int	my_get_next_str_unraw(t_struct *var);
int	my_get_next_str(t_struct *var);
int	builtin_alias(t_struct *var, char **tab, int end);
int	mysh(t_struct *);
int	exe_cmd(t_struct *var, char **tab);
char	**do_cmd(char *, char **);
char	*my_getstock(t_stock **, char *);
char	*prepare_for_tab(char *);
char	**do_env(t_stock **);
void	gere_sig();
int	my_get_envp(t_struct *, char **);
int	my_unsetenv(t_struct *);
int	builtin(t_struct *, char **);
int	my_cd(t_struct *, char **);
int	my_setenv(t_struct *);
int	my_check_setenv(t_struct *);
int	find_old_setenv(t_struct *);
int	my_exit(t_struct *var, char **);
char	**do_tab_exec(t_stock **);
int     my_write(t_struct *var, char **tab1, char **tab2);
int	parseur(t_struct *var);
int	exe_solo(t_struct *, char **);
int	fct_pipe(t_struct *var, char **, char **);
int	un_raw_mod();
char	**wordtab_env(char *str);
int	type_zero(t_struct *var, t_buff *cmd);
int	type_write(t_struct *var, t_buff *cmd, t_buff *next);
int	type_pipe(t_struct *var, t_buff *cmd, t_buff *next);

#endif /* !MYSH_H_ */
