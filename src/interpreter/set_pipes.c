#include "interpreter.h"

static int	set_last_pipe(t_globvar **g_var)
{
	t_pipe	*comm_pipe;

	comm_pipe = malloc(sizeof(t_pipe));
	if (!comm_pipe)
		return (1);
	comm_pipe->pid = 0;
	comm_pipe->last = 1;
	comm_pipe->write[0] = -1;
	comm_pipe->read[0] = -1;
	if ((*g_var)->next_read[0] != -1)
	{
		comm_pipe->read[0] = (*g_var)->next_read[0];
		comm_pipe->read[1] = (*g_var)->next_read[1];
		(*g_var)->next_read[0] = -1;
	}
	(*g_var)->pipes = ft_lstnew(comm_pipe);
	return (0);
}

static int	pipe_manager(t_globvar **g_var)
{
	t_pipe	*comm_pipe;
	int		aux[2];

	comm_pipe = malloc(sizeof(t_pipe));
	if (!comm_pipe)
		return (1);
	if (pipe(aux) == -1)
		return (1);
	comm_pipe->pid = 0;
	comm_pipe->last = 0;
	comm_pipe->write[0] = aux[0];
	comm_pipe->write[1] = aux[1];
	comm_pipe->read[0] = -1;
	if ((*g_var)->next_read[0] != -1)
	{
		comm_pipe->read[0] = (*g_var)->next_read[0];
		comm_pipe->read[1] = (*g_var)->next_read[1];
	}
	else
		comm_pipe->last = -1;
	(*g_var)->next_read[0] = aux[0];
	(*g_var)->next_read[1] = aux[1];
	(*g_var)->pipes = ft_lstnew(comm_pipe);
	return (0);
}

int	set_pipes(int const next, t_globvar **g_var)
{
	if (next)
	{
		if (pipe_manager(g_var))
			return (1);
		return (0);
	}
	if (set_last_pipe(g_var))
		return (1);
	return (0);
}
