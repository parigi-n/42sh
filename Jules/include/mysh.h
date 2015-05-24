/*
** mysh.h for mysh.h in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Jan 15 09:24:53 2015 Jules Vautier
** Last update Sun May 24 17:39:02 2015 Nicolas PARIGI
*/

#ifndef MYSH_H_
# define MYSH_H_

# define SEGFAUL	11
# define FAIL_STATUS	512
# define RC_NAME	".tcshrc"
# define DEFAULT_PROMPT "\033[1;36m salut \033[0m"

int	mysh(t_struct *);
int	exe_cmd(t_struct *var, char **);
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
int	redir(t_struct *, char **);
int	parseur(t_struct *var);
int	exe_solo(t_struct *, char **);
int	fct_pipe(t_struct *var, char **, char **);
char	**wordtab_env(char *str);
int	my_prompt(char *, t_stock **);
int	pipe_me(int *fd, int pipefd[2], t_struct *var, t_buff *tmp);

#endif /* !MYSH_H_ */
