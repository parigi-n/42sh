/*
** sttruct.h for struct in /home/vautie_a/rendu/PSU_2014_42sh/Jules/include
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Apr 29 16:50:15 2015 Jules Vautier
** Last update Thu Apr 30 18:10:29 2015 Martin PELLEMOINE
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct  s_list
{
  char          *str;
  struct s_list *next;
}               t_list;

typedef struct  s_buff
{
  char          *buff;
  char          **tab;
  int           type;
  struct s_buff *next;
}		t_buff;

typedef struct	s_term
{
  char		*go;
  char		*cl;
  char		*ve;
  char		*vi;
  int		i;
  int		hist;
  int		line;
}		t_term;

typedef struct  s_struct
{
  t_term	term;
  int           check;
  int           pid;
  int           len;
  int           status;
  char          *new;
  unsigned char	*buff;
  char          **tab;
  char          **envi;
  char          **envp;
  char          **envtab;
  t_list        *list;
  t_buff        *buffer;
}		t_struct;

#endif /* !STRUCT_H_ */
