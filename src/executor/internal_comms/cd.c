#include "internal_comms.h"

static void	concat_dir(t_list_crud *envp)
{
	size_t	index;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	find_var("OLDPWD", &index, envp);
	update(envp, index, get_value("PWD", envp));
	find_var("PWD", &index, envp);
	update(envp, index, cwd);
	free(cwd);
}

static void	error_cd(t_globvar *g_var)
{
	perror("cd:");
	g_var->last_exit_code = 1;
}

int	cd(char **args, t_globvar *g_var)
{
	int		error;

	g_var->last_exit_code = 0;
	if (((t_pipe *)g_var->pipes->content)->read[0] == -1
		&& ((t_pipe *)g_var->pipes->content)->write[0] == -1)
	{
		if (args[1] == NULL)
		{
			chdir(get_value("HOME", g_var->envp));
			concat_dir(g_var->envp);
		}
		else
		{
			error = chdir(args[1]);
			if (error == -1)
				error_cd(g_var);
			else
				concat_dir(g_var->envp);
		}
		return (0);
	}
	if (!access(args[1], F_OK))
		error_cd(g_var);
	return (0);
}
