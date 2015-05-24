/*
** mysh.h for mysh.h in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Jan 15 09:24:53 2015 Jules Vautier
** Last update Wed May 13 11:49:17 2015 Jules Vautier
*/

#ifndef MYSH_H_
# define MYSH_H_

# define FAIL_STATUS	65280
# define TYPE_NEW	0
# define TYPE_DROITE	1
# define TYPE_PIPE	2
# define TYPE_GAUCHE	3
# define RC_NAME	".bashrc"
# define QUOTE		39

int	mysh(t_struct *);
int	exe_cmd(t_struct *var, char **tab);
char	**do_cmd(char *, char **);
char	*my_getstock(t_stock **, char *);
char	*get_next_line(int);
char	*prepare_for_tab(char *);
char	**do_env(t_stock **);
void	gere_sig();
int	my_get_envp(t_struct *, char **);
int	my_unsetenv(t_struct *);
char	**my_cpy_tab(char **, char **, int);
int	builtin(t_struct *, char **);
int	my_cd(t_struct *, char **);
int	my_setenv(t_struct *);
int	my_check_setenv(t_struct *);
int	find_old_setenv(t_struct *);
int	my_exit(t_struct *var, char **);
int	init_struct(t_struct *, char *envp[]);
char	**do_tab_exec(t_stock **);
char	*next_buff(char *, int);
char	*parsing_add(char *, int, char *);
int	find_type(char *);
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
