#include "internal_comms.h"

static char	*build_string(char **args)
{
	char	*res;
	size_t	i;

	res = 0;
	if (args[0])
	{
		if (ft_append(&res, args[0]))
			return (0);
	}
	i = 1;
	while (args[i])
	{
		ft_append(&res, " ");
		if (ft_append(&res, args[i]))
			return (0);
		++i;
	}
	return (res);
}

static int	writer(char **args, int const newline, int const fd)
{
	char	*output;

	output = build_string(args);
	if (!output)
		return (1);
	if (!newline)
		ft_putstr_fd(output, fd);
	else
		ft_putendl_fd(output, fd);
	free(output);
	return (0);
}

static void	set_start_output(char ***aux, char **args, int *newline)
{
	size_t	i;

	if (!ft_strcmp(args[1], "-n"))
	{
		*newline = 0;
		i = 2;
		while (args[i] && !ft_strcmp(args[i], "-n"))
			++i;
		*aux = &args[i];
	}
	else
		*aux = &args[1];
	return ;
}

static int	failure_exit(t_globvar *g_var)
{
	g_var->last_exit_code = 1;
	return (1);
}

int	echo(char **args, t_globvar *g_var)
{
	int		fd;
	int		newline;
	char	**aux;

	g_var->last_exit_code = 0;
	newline = 1;
	if (get_fd(&fd, g_var))
		return (0);
	if (!args[1])
	{
		ft_putendl_fd("", fd);
		return (0);
	}
	set_start_output(&aux, args, &newline);
	if (!aux[0])
	{
		ft_putstr_fd("", fd);
		return (0);
	}
	if (writer(aux, newline, fd))
		return (failure_exit(g_var));
	if (g_var->redir.output_queue)
		close(fd);
	return (0);
}
