#include "executor.h"
#include "internal_comms/internal_comms.h"

static int	call_ifunc(int (*internal_func)(char **args, t_globvar *g_var),
char **args, t_globvar *g_var)
{
	if ((*internal_func)(args, g_var))
		return (1);
	return (0);
}

static int	caller(char **args, t_globvar *g_var)
{
	int	(*internal_func)(char **args, t_globvar *g_var);

	internal_func = NULL;
	if (!ft_strcmp(args[0], "echo"))
		internal_func = echo;
	else if (!ft_strcmp(args[0], "export"))
		internal_func = export;
	else if (!ft_strcmp(args[0], "pwd"))
		internal_func = pwd;
	else if (!ft_strcmp(args[0], "unset"))
		internal_func = unset;
	else if (!ft_strcmp(args[0], "cd"))
		internal_func = cd;
	else if (!ft_strcmp(args[0], "env"))
		internal_func = env;
	else
		internal_func = ft_exit;
	if (call_ifunc(internal_func, args, g_var))
		return (1);
	return (0);
}

int	internal(char **args, t_globvar *g_var)
{
	if (caller(args, g_var))
		return (1);
	return (0);
}
