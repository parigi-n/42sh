/*
** sttruct.h for struct in /home/vautie_a/rendu/PSU_2014_42sh/Jules/include
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Apr 29 16:50:15 2015 Jules Vautier
** Last update Fri May 15 11:14:22 2015 Jules Vautier
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_stock
{
  char			*name;
  char			*comment;
  struct s_stock	*next;
}			t_stock;

typedef struct		s_buff
{
  char			*buff;
  char			**tab;
  char			**display;
  int			type;
  struct s_buff		*next;
  struct s_buff		*prev;
}			t_buff;

typedef struct		s_hist
{
  char			*str;
  int			nb;
  struct s_hist		*next;
}			t_hist;

typedef struct		s_term
{
  char			*go;
  char			*cl;
  char			*ve;
  char			*vi;
  int			i;
  int			pos;
  int			lim_hist;
  t_hist		*hist;
}			t_term;

typedef struct		s_struct
{
  t_term		term;
  int			check;
  int			pid;
  int			len;
  int			status;
  char			*new;
  unsigned char		*buff;
  char			**tab;
  char			**envi;
  char			**envp;
  char			**envtab;
  t_stock		*env;
  t_stock		*alias;
  t_buff		*buffer;
}			t_struct;

#endif /* !STRUCT_H_ */
