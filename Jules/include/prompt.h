/*
** prompt.h for prompt.h in /home/parigi_n/Testrendu/PSU_2014_42sh/Nico/mysh/include
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat May 16 16:56:10 2015 Nicolas PARIGI
** Last update Sun May 24 17:39:27 2015 Nicolas PARIGI
*/

#ifndef PROMPT_H_
# define PROMPT_H_

typedef struct	s_prompt
{
  int           (*fct_prompt)(t_stock **env);
  char          param;
}		t_prompt;

int		flag_backslash(t_stock **env);
int		flag_mod(t_stock **env);
int		flag_name(t_stock **env);
int		flag_fullhost(t_stock **env);
int		flag_host(t_stock **env);
int		flag_hist(t_stock **env);
int		flag_escape_open(t_stock **env);
int		flag_escape_close(t_stock **env);
int		flag_current_dir(t_stock **env);
int		flag_current_dir_home(t_stock **env);
int		flag_time_hour_ampm(t_stock **env);
int		flag_time_hour(t_stock **env);
int		flag_time_hour_precise(t_stock **env);
int		flag_time_day_str(t_stock **env);
int		flag_time_day_nbr(t_stock **env);
int		flag_time_month_str(t_stock **env);
int		flag_time_month_nbr(t_stock **env);
int		flag_time_year_first(t_stock **env);
int		flag_time_year_complete(t_stock **env);
char		*pwd_home(char *home, char *path);
int		prompt_bashrc(t_struct *var, char *raw_line);
int		bashrc_prompt_fct(t_struct *var, char **);
int		my_prompt(char *prompt_line, t_stock **env);
int		check_quote(char *line);

#endif /* !PROMPT_H_ */
