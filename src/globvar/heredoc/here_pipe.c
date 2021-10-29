#include "heredoc.h"

static char	*get_heredoc_content(void *content)
{
	t_heredoc	*heredoc;

	heredoc = (t_heredoc *)content;
	return (heredoc->input);
}

int	set_here_pipe(t_here *here)
{
	char	*msg;

	msg = 0;
	if (!here->lst_track)
		return (0);
	if (pipe(here->here_pipe) == -1)
		return (1);
	msg = get_heredoc_content(here->lst_track->content);
	ft_putstr_fd(msg, here->here_pipe[1]);
	return (0);
}

void	close_here_pipe(t_here *here)
{
	if (!here->lst_track)
		return ;
	close(here->here_pipe[0]);
	close(here->here_pipe[1]);
	return ;
}
