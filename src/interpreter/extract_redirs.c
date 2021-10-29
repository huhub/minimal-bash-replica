#include "interpreter.h"

int	found_redir(char const *comm, t_extract_data *xdata,
char **comm_no_redir, t_globvar *g_var)
{
	if (comm[xdata->i] == '<')
	{
		if (input_redir(comm, xdata, g_var))
			return (1);
	}
	else if (comm[xdata->i] == '>')
	{
		if (output_redir(comm, xdata, g_var))
			return (1);
	}
	if (comm[xdata->chunk_start] != '<' && comm[xdata->chunk_start] != '>')
	{
		if (cut_and_append(xdata->chunk_start, xdata->i - xdata->inc, comm,
				comm_no_redir))
			return (1);
	}
	xdata->chunk_start = xdata->i + xdata->redir_len;
	xdata->i += xdata->redir_len;
	return (0);
}

int	end_redir_extract(char const *comm, size_t const chunk_start,
size_t const iter, char **comm_no_redir)
{
	if (comm[chunk_start] != '<' && comm[chunk_start] != '>')
	{
		if (!(*comm_no_redir))
		{
			if (mod_strchr(comm, '>') || mod_strchr(comm, '<'))
				*comm_no_redir = ft_strdup("");
			else
				*comm_no_redir = ft_strdup(comm);
		}
		else
		{
			if (cut_and_append(chunk_start, iter, comm, comm_no_redir))
				return (1);
		}
	}
	return (0);
}

void	init_extract_data(t_extract_data *xdata)
{
	xdata->chunk_start = 0;
	xdata->redir_len = 0;
	xdata->inc = 0;
}

int	extract_redirs(char const *comm, char **comm_no_redir,
t_globvar *g_var)
{
	t_extract_data	xdata;

	init_extract_data(&xdata);
	xdata.i = 0;
	while (1)
	{
		if (comm[xdata.i] == '"' || comm[xdata.i] == '\'')
		{
			if (comm[xdata.i] == '"')
				double_quote((char *)comm, &xdata.i);
			else
				single_quote((char *)comm, &xdata.i);
			xdata.i += 1;
		}
		else if (comm[xdata.i] == '<' || comm[xdata.i] == '>')
		{
			if (found_redir(comm, &xdata, comm_no_redir, g_var))
				return (1);
		}
		else if (!comm[xdata.i])
			return (end_redir_extract(comm, xdata.chunk_start, xdata.i,
					comm_no_redir));
		else
			xdata.i += 1;
	}
}
