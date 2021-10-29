#include "executor.h"

static int	non_existent(t_globvar *g_var)
{
	g_var->last_exit_code = 127;
	custom_err_msg("command not found\n");
	return (0);
}

static int	is_executable(char *path, t_globvar *g_var)
{
	if (access(path, F_OK))
	{
		custom_err_msg("command not found\n");
		g_var->last_exit_code = 127;
		free(path);
		return (0);
	}
	if (access(path, X_OK))
	{
		perror("not executable");
		g_var->last_exit_code = 126;
		free(path);
		return (0);
	}	
	return (1);
}

static int	add_path(char **program_path, char const *program_name,
t_globvar *g_var)
{
	char	*dir_path;
	char	*aux;

	dir_path = get_path(program_name, g_var);
	if (!dir_path)
	{
		*program_path = 0;
		return (0);
	}
	aux = ft_strjoin(dir_path, "/");
	if (!aux)
		return (1);
	free(dir_path);
	*program_path = ft_strjoin(aux, program_name);
	if (!(*program_path))
		return (1);
	free(aux);
	return (0);
}

int	external(char **args, t_globvar *g_var)
{
	char	*program_path;
	int		exit_code;

	if (!check_path(args[0]))
	{
		if (add_path(&program_path, args[0], g_var))
			return (1);
		if (!program_path)
			return (non_existent(g_var));
	}
	else
	{
		program_path = ft_strdup(args[0]);
		if (!program_path)
			return (1);
	}
	if (!is_executable(program_path, g_var))
		return (0);
	exit_code = 0;
	if (external_exec(program_path, args, g_var))
		exit_code = 1;
	free(program_path);
	return (exit_code);
}
