#include "interpreter.h"

void	store_pipes(t_list **pipes, t_list **s_pipes)
{
	if (!(*pipes))
		return ;
	if (!(*s_pipes))
		*s_pipes = *pipes;
	else
		ft_lstadd_back(s_pipes, *pipes);
	*pipes = 0;
}

static void	close_pipes(t_list **pipes)
{
	t_list	*last_pipe;
	t_pipe	*comm_pipe;
	int		reset;

	reset = 0;
	if (ft_lstsize(*pipes) == 1)
		reset = 1;
	last_pipe = ft_lstlast(*pipes);
	comm_pipe = (t_pipe *)last_pipe->content;
	if (comm_pipe->last == 1)
		close(comm_pipe->read[0]);
	if (!comm_pipe->last)
	{
		close(comm_pipe->write[1]);
		close(comm_pipe->read[0]);
	}
	if (comm_pipe->last == -1)
		close(comm_pipe->write[1]);
	if (comm_pipe->pid)
		return ;
	free(comm_pipe);
	free(last_pipe);
	last_pipe = 0;
	if (reset)
		*pipes = 0;
}

static int	failure_exit(char **pipeline)
{
	free_2dim_str(pipeline);
	return (1);
}

int	divider(char const *input, t_globvar *g_var)
{
	t_list	*s_pipes;
	char	**pipeline;
	int		next;
	size_t	i;

	s_pipes = 0;
	pipeline = ft_splitter(input, '|');
	if (!pipeline)
		return (1);
	i = 0;
	while (pipeline[i])
	{
		next = 0;
		if (pipeline[i + 1])
			next = 1;
		if (parser(pipeline[i], next, g_var))
			return (failure_exit(pipeline));
		close_pipes(&g_var->pipes);
		store_pipes(&g_var->pipes, &s_pipes);
		++i;
	}
	if (waiter(g_var, s_pipes))
		return (1);
	free_2dim_str(pipeline);
	return (0);
}
