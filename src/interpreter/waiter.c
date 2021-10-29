#include "interpreter.h"
#include <sys/types.h>
#include <sys/wait.h>

static void	close_external_pipe(pid_t target, t_list **pipes)
{
	t_list	*iter;
	t_list	*prev;
	t_pipe	*comm_pipe;

	iter = *pipes;
	prev = 0;
	while (iter)
	{
		if (((t_pipe *)iter->content)->pid == target)
			break ;
		prev = iter;
		iter = iter->next;
	}
	if (!iter)
		return ;
	if (prev)
		prev->next = iter->next;
	else if (iter->next)
		*pipes = iter->next;
	comm_pipe = (t_pipe *)iter->content;
	free(comm_pipe);
	free(iter);
	iter = 0;
}

static void	set_last_exit(int const status, t_globvar *g_var, t_list *comm_pipe)
{
	if (((t_pipe *)comm_pipe->content)->last == 1
		&& WIFEXITED(status))
		g_var->last_exit_code = WEXITSTATUS(status);
	else if (((t_pipe *)comm_pipe->content)->last == 1
		&& WIFSIGNALED(status))
		g_var->last_exit_code = 128 + WTERMSIG(status);
	else if (((t_pipe *)comm_pipe->content)->last == 1)
		g_var->last_exit_code = 0;
}

static t_list	*get_pipe_by_id(pid_t target, t_list *pipes)
{
	t_list	*iter;

	iter = pipes;
	while (iter)
	{
		if (((t_pipe *)iter->content)->pid == target)
			return (iter);
		iter = iter->next;
	}
	return (0);
}

int	waiter(t_globvar *g_var, t_list *s_pipes)
{
	pid_t	id_child;
	int		status;
	t_list	*comm_pipe;
	size_t	i;

	if (!s_pipes)
		return (0);
	i = ft_lstsize(s_pipes);
	while (i)
	{
		id_child = waitpid(0, &status, 0);
		if (id_child == -1)
			return (1);
		comm_pipe = get_pipe_by_id(id_child, s_pipes);
		set_last_exit(status, g_var, comm_pipe);
		close_external_pipe(id_child, &s_pipes);
		--i;
	}
	g_var->exec = 0;
	return (0);
}
