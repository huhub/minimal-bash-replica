#include "internal_comms.h"

static int	is_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

int	ft_exit(char **args, t_globvar *g_var)
{
	if (args[1])
	{
		if (args[2])
		{
			g_var->last_exit_code = 1;
			custom_err_msg("exit: Too many arguments.\n");
			return (0);
		}
		if (is_num(args[1]))
			g_var->last_exit_code = ft_atoi(args[1]);
		else
		{
			g_var->last_exit_code = 2;
			custom_err_msg("exit: Numeric argument required.\n");
			return (0);
		}
	}
	if (((t_pipe *)g_var->pipes->content)->read[0] == -1
		&& ((t_pipe *)g_var->pipes->content)->write[0] == -1)
		g_var->exit_command = 1;
	return (0);
}
