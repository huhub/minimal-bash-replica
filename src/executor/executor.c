#include "executor.h"
#include "utils/i_comms_utils.h"

static void	empty_command(t_globvar *g_var)
{
	int	fd;

	fd = 0;
	g_var->last_exit_code = 0;
	if (get_fd(&fd, g_var))
	{
		g_var->last_exit_code = 1;
		return ;
	}
	if (fd != -1 && fd > 2)
		close(fd);
	if (g_var->empty_command)
	{
		g_var->last_exit_code = 127;
		custom_err_msg("command not found\n");
	}
	return ;
}

static int	fill_envp_exec(char ***envp_exec, t_list_crud *envp)
{
	t_node	*iter;
	size_t	i;

	if (*envp_exec)
		free_2dim_str(*envp_exec);
	*envp_exec = malloc(sizeof(char *) * (envp->size + 1));
	(*envp_exec)[envp->size] = 0;
	iter = envp->first_item;
	i = 0;
	while (iter)
	{
		(*envp_exec)[i] = 0;
		ft_append(&(*envp_exec)[i], iter->command);
		ft_append(&(*envp_exec)[i], "=");
		if (ft_append(&(*envp_exec)[i], iter->value))
			return (1);
		iter = iter->next;
		++i;
	}	
	return (0);
}

static int	classifier(char const *program)
{
	if (!ft_strcmp(program, "echo") || !ft_strcmp(program, "cd")
		|| !ft_strcmp(program, "pwd") || !ft_strcmp(program, "export")
		|| !ft_strcmp(program, "unset") || !ft_strcmp(program, "env")
		|| !ft_strcmp(program, "exit"))
		return (1);
	return (0);
}

int	executor(char **args, t_globvar *g_var)
{
	if (!args[0] || !args[0][0] || g_var->empty_command)
	{
		empty_command(g_var);
		return (0);
	}
	if (classifier(args[0]))
	{
		if (!ft_strcmp(args[0], "export"))
		{
			if (fill_envp_exec(&g_var->envp_exec, g_var->envp))
				return (1);
		}
		if (internal(args, g_var))
			return (1);
		return (0);
	}
	if (fill_envp_exec(&g_var->envp_exec, g_var->envp))
		return (1);
	if (external(args, g_var))
		return (1);
	return (0);
}
