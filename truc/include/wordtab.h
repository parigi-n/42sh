/*
** wordtab.h for wordtab in /home/vautie_a/rendu/Piscine_C_J08/wordtab
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Oct 28 19:11:11 2014 jules vautier
** Last update Thu Mar 12 10:13:38 2015 Jules Vautier
*/

#ifndef WORDTAB_H_
# define WORDTAB_H_

typedef struct	s_wordtab
{
  char		**tab;
  int		i;
  int		n;
  int		x;
  int		len;
  int		wordlen;
}		t_wordtab;

char	*epur_str(char *);
int	my_count_nbr(char *dest);
int	my_wordlen(char *, int );
int	my_wordlen(char *dest, int i);
char	**my_word_to_tab(char *);
void	freetab(char **);
void	my_show_tab(char **);
int	my_tablen(char **);
char	**tabcpy(char **tab);

#endif /* !WORDTAB_H_ */
