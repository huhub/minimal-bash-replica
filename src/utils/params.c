#include "utils.h"

void	parameter(t_globvar *g_var, char **argv, char **envp)
{
	char	*varname;
	size_t	i;

	g_var->argv = argv;
	g_var->envp = get_new_list();
	i = -1;
	while (envp[++i] != NULL)
	{
		varname = command_line_var(envp[i], '=');
		if (ft_strcmp(varname, "OLDPWD"))
			add_crud(g_var->envp, varname,
				ft_strchr(envp[i], '=') + 1);
		else
			add_crud(g_var->envp, varname,
				"");
		free(varname);
	}
	return ;
}
