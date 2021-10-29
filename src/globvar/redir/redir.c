#include "redir.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_redir_read_fd(t_redir const *redir, int *fd)
{
	*fd = -1;
	if (redir)
	{
		if (redir->input_filepath)
		{
			*fd = open(redir->input_filepath, O_RDONLY);
			if (*fd == -1)
				return (1);
		}
	}
	if (*fd == -1)
		return (1);
	return (0);
}

static void	fd_assignment(t_output_content *output_path, int *fd)
{
	if (output_path->filepath && output_path->append)
		*fd = open(output_path->filepath, O_WRONLY | O_APPEND | O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	else
		*fd = open(output_path->filepath, O_RDWR | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
}

int	get_redir_write_fd(t_redir const *redir, int *fd)
{
	t_list				*head;
	t_output_content	*output_path;

	*fd = -1;
	if (redir)
	{
		head = redir->output_queue;
		while (head)
		{
			output_path = (t_output_content *)head->content;
			fd_assignment(output_path, fd);
			if (*fd == -1)
				return (1);
			if (head->next)
				close(*fd);
			head = head->next;
		}
	}
	if (*fd == -1)
		return (1);
	return (0);
}

static void	del_output_content(void *content)
{
	t_output_content	*out_cont;

	out_cont = (t_output_content *)content;
	free(out_cont->filepath);
	free(out_cont);
	out_cont = 0;
}

void	free_redir(t_redir *redir)
{
	if (redir->input_filepath)
	{
		free(redir->input_filepath);
		redir->input_filepath = 0;
	}
	if (redir->output_queue)
		ft_lstclear(&redir->output_queue, del_output_content);
}
