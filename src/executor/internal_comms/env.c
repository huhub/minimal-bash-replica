#include "internal_comms.h"

int	env(char **args, t_globvar *g_var)
{
	t_node	*iter;
	int		fd;

	g_var->last_exit_code = 0;
	if (args[1])
		return (0);
	if (get_fd(&fd, g_var))
		return (1);
	iter = g_var->envp->first_item;
	while (iter)
	{
		if (iter->value[0])
		{
			ft_putstr_fd(iter->command, fd);
			ft_putstr_fd("=", fd);
			ft_putendl_fd(iter->value, fd);
		}
		iter = iter->next;
	}
	return (0);
}
