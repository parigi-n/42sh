/*
** string.h for string in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 15:46:15 2015 Jules Vautier
** Last update Sun May 24 10:23:07 2015 Jules Vautier
*/

#ifndef STRING_H_
# define STRING_H_

# define SUCCES		0
# define ERROR		-1
# define INVALID_READ	"Invalid read.\n"
# define INVALID_CMD	"Invalid command.\n"
# define INVALID_PIPE	"Invalid pipe\n"
# define INVALID_DIR	"Invalid redirection\n"
# define INVALID_ALIAS	"Invalid alias syntax\n"
# define INVALID_SYNTAX	"Invalid syntax in cmd %s\n"
# define ERROR_PATH	"Can't find the path.\n"
# define ERROR_HOME	"Can't find the home.\n"
# define ERROR_OPEN	"Error Open.\n"
# define ERROR_MALLOC	"Error Malloc.\n"
# define ERROR_INIT	"Error in init function.\n"
# define ERROR_SIGNAL	"Error Signal.\n"
# define ERROR_DUP	"Error withe dup2.\n"
# define ERROR_CLOSE	"Error with Close.\n"
# define ERROR_SIGNAL	"Error Signal.\n"
# define ERROR_PIPE	"Error with pipe.\n"
# define ERROR_FORK	"Error with fork.\n"
# define ERROR_KILL	"Error with kill.\n"

/* .tcshrc */

# define ERROR_NO_RC	"No .tcshrc found in HOME folder or 42sh folder.\n"

/* CD */

# define ERROR_NOPWD	"Error : Can't get previous working directory.\n"
# define ERROR_NOOLDPWD	"Error : Can't set previous working directory.\n"
# define ERROR_NONEWPWD	"Error : Can't set actual working directory (Pwd).\n"
# define ERROR_CD	"Error : Undefined error in CD.\n"
#endif /* !STRING_H_ */
