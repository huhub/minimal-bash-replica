#include "interpreter.h"

static void	manage_heredoc(char const *comm, t_extract_data *xdata,
t_globvar *g_var)
{
	xdata->inc = 2;
	xdata->i += xdata->inc;
	xdata->redir_len = get_redir_len(&comm[xdata->i]);
	if (g_var->here.lst)
	{
		if (!g_var->here.lst_track)
			g_var->here.lst_track = g_var->here.lst;
		else
			g_var->here.lst_track = g_var->here.lst_track->next;
	}
}

int	input_redir(char const *comm, t_extract_data *xdata,
t_globvar *g_var)
{
	if (comm[xdata->i + 1] == '<')
		manage_heredoc(comm, xdata, g_var);
	else
	{
		xdata->inc = 1;
		xdata->i += xdata->inc;
		xdata->redir_len = get_redir_len(&comm[xdata->i]);
		if (g_var->redir.input_filepath)
		{
			free(g_var->redir.input_filepath);
			g_var->redir.input_filepath = 0;
		}
		g_var->redir.input_filepath = get_filename(&comm[xdata->i]);
		if (!g_var->redir.input_filepath)
			return (1);
	}
	return (0);
}

static void	get_len(char const *comm, t_extract_data *xdata,
t_output_content *out_cont)
{
	if (comm[xdata->i + 1] == '>')
	{
		xdata->inc = 2;
		xdata->i += xdata->inc;
		xdata->redir_len = get_redir_len(&comm[xdata->i]);
		out_cont->append = 1;
	}
	else
	{
		xdata->inc = 1;
		xdata->i += xdata->inc;
		xdata->redir_len = get_redir_len(&comm[xdata->i]);
		out_cont->append = 0;
	}
}

int	output_redir(char const *comm, t_extract_data *xdata,
t_globvar *g_var)
{
	t_list				*out;
	t_output_content	*out_cont;

	out_cont = malloc(sizeof(t_output_content));
	if (!out_cont)
		return (1);
	get_len(comm, xdata, out_cont);
	out_cont->filepath = get_filename(&comm[xdata->i]);
	if (!out_cont->filepath)
	{
		free(out_cont);
		return (1);
	}
	out = ft_lstnew(out_cont);
	if (!g_var->redir.output_queue)
		g_var->redir.output_queue = out;
	else
		ft_lstadd_back(&g_var->redir.output_queue, out);
	return (0);
}
