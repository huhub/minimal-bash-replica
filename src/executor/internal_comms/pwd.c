#include "internal_comms.h"

int	pwd(char **args, t_globvar *g_var)
{
	int	fd;

	g_var->last_exit_code = 0;
	if (args[1])
		return (0);
	if (get_fd(&fd, g_var))
		return (1);
	ft_putendl_fd(getcwd(NULL, 0), fd);
	return (0);
}
