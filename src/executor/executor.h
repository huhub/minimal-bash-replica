#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../globvar/globvar.h"

/*
**	executor.c
*/

int	executor(char **args, t_globvar *g_var);

/*
**	internal.c
*/

int	internal(char **args, t_globvar *g_var);

/*
**	external.c
*/

int	external(char **args, t_globvar *g_var);

/*
**	external_exec.c
*/

int	external_exec(char const *program, char **args, t_globvar *g_var);

#endif
