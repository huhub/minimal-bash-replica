#include "executor.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

static void	set_dst_fd(t_globvar *g_var, char **args)
{
	int	dst_fd;

	if (g_var->redir.output_queue)
	{
		if (get_redir_write_fd(&g_var->redir, &dst_fd) || dst_fd == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		dst_fd = ((t_pipe *)g_var->pipes->content)->write[1];
		close(((t_pipe *)g_var->pipes->content)->write[0]);
	}
	if (dup2(dst_fd, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(dst_fd);
}

static void	set_src_fd(t_globvar *g_var)
{
	int	src_fd;

	if (g_var->here.lst_track)
	{
		src_fd = g_var->here.here_pipe[0];
		close(g_var->here.here_pipe[1]);
	}
	else if (g_var->redir.input_filepath)
	{
		if (get_redir_read_fd(&g_var->redir, &src_fd) || src_fd == -1)
		{
			perror(g_var->redir.input_filepath);
			exit(EXIT_FAILURE);
		}
	}
	else
		src_fd = ((t_pipe *)g_var->pipes->content)->read[0];
	if (dup2(src_fd, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(src_fd);
}

static void	execute_program(char const *program, char **args,
t_globvar *g_var)
{
	if (g_var->redir.input_filepath
		|| ((t_pipe *)g_var->pipes->content)->read[0] != -1
		|| g_var->here.lst_track)
		set_src_fd(g_var);
	if (g_var->redir.output_queue
		|| ((t_pipe *)g_var->pipes->content)->write[0] != -1)
		set_dst_fd(g_var, args);
	execve(program, args, g_var->envp_exec);
}

static int	launch_process(char const *program, char **args, t_globvar *g_var)
{
	pid_t	child;

	child = fork();
	if (child == -1)
		return (1);
	if (child == 0)
	{
		errno = 0;
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execute_program(program, args, g_var);
		exit(errno);
	}
	else
	{
		((t_pipe *)ft_lstlast(g_var->pipes)->content)->pid = child;
		if (g_var->here.lst_track)
			close_here_pipe(&g_var->here);
		return (0);
	}
}

int	external_exec(char const *program, char **args, t_globvar *g_var)
{
	if (!g_var->exec)
		g_var->exec = 1;
	if (launch_process(program, args, g_var))
		return (1);
	return (0);
}
