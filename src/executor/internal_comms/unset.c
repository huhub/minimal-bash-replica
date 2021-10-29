#include "internal_comms.h"

int	unset(char **args, t_globvar *g_var)
{
	size_t	index;
	size_t	i;

	index = 0;
	i = 1;
	g_var->last_exit_code = 0;
	if (!args[i])
		return (0);
	while (args[i])
	{
		if (!check_valid_varname(args[i]))
		{
			if (find_var(args[i], &index, g_var->envp))
				removed(g_var->envp, index);
		}
		else
		{
			custom_err_msg("unset: Not a valid identifier.\n");
			if (g_var->last_exit_code != 1)
				g_var->last_exit_code = 1;
		}
		++i;
	}
	return (0);
}
