#include "../i_comms_utils.h"

int	get_fd(int *fd, t_globvar *g_var)
{
	int	fd_in;

	*fd = STDOUT_FILENO;
	if (g_var->redir.input_filepath)
	{
		if (get_redir_read_fd(&g_var->redir, &fd_in) || fd_in == -1)
		{
			perror(g_var->redir.input_filepath);
			g_var->last_exit_code = 1;
			return (1);
		}
		close(fd_in);
	}
	if (g_var->redir.output_queue)
	{
		if (get_redir_write_fd(&g_var->redir, fd) || *fd == -1)
		{
			perror(g_var->redir.input_filepath);
			g_var->last_exit_code = 1;
			return (1);
		}
	}
	else if (((t_pipe *)g_var->pipes->content)->write[0] != -1)
		*fd = ((t_pipe *)g_var->pipes->content)->write[1];
	return (0);
}
