#include "internal_comms.h"

static void	process_assignment(char **assignment, char *arg, t_globvar *g_var)
{
	size_t	index;

	index = 0;
	if (!assignment[0] || check_valid_varname(assignment[0]))
	{
		custom_err_msg("export: Not a valid identifier.\n");
		if (g_var->last_exit_code != 1)
			g_var->last_exit_code = 1;
	}
	else if (find_var(assignment[0], &index, g_var->envp))
	{
		if (mod_strchr(arg, '='))
			update(g_var->envp, index, assignment[1]);
	}
	else
		add_crud(g_var->envp, assignment[0], assignment[1]);
}

int	with_args(char **args, t_globvar *g_var)
{
	char	**assignment;
	size_t	i;

	assignment = 0;
	i = 1;
	while (args[i])
	{
		assignment = split_var(args[i]);
		if (!assignment)
			return (1);
		process_assignment(assignment, args[i], g_var);
		free_2dim_str(assignment);
		++i;
	}
	return (0);
}

static int	var_printer(char *sorted_env, int const fd)
{
	char	*var_out;
	char	**splitted;

	var_out = 0;
	if (ft_append(&var_out, "declare -x "))
		return (1);
	splitted = split_var(sorted_env);
	if (!splitted)
		return (1);
	ft_append(&var_out, splitted[0]);
	ft_append(&var_out, "=\"");
	ft_append(&var_out, splitted[1]);
	if (ft_append(&var_out, "\""))
		return (1);
	ft_putendl_fd(var_out, fd);
	free(var_out);
	return (0);
}

int	no_args(t_globvar *g_var, int const fd)
{
	char	**sorted_env;
	size_t	i;

	sorted_env = alpha_sort(g_var->envp_exec, g_var->envp->size);
	if (!sorted_env)
		return (1);
	i = 0;
	while (sorted_env[i])
	{
		if (var_printer(sorted_env[i], fd))
			return (1);
		++i;
	}
	free_2dim_str(sorted_env);
	return (0);
}

int	export(char **args, t_globvar *g_var)
{
	int	fd;

	g_var->exit_command = 0;
	if (get_fd(&fd, g_var))
		return (0);
	if (!args[1])
	{
		if (no_args(g_var, fd))
			return (1);
	}
	else
	{
		if (with_args(args, g_var))
			return (1);
	}
	return (0);
}
