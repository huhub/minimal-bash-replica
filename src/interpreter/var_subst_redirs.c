#include "interpreter.h"

static int	output_redir_var_subst(t_globvar *g_var)
{
	t_output_content	*out_cont;
	t_list				*iter;
	char				*new_filename;

	if (!g_var->redir.output_queue)
		return (0);
	iter = g_var->redir.output_queue;
	while (iter)
	{
		out_cont = (t_output_content *)iter->content;
		new_filename = var_subst(out_cont->filepath, g_var);
		if (!new_filename)
			return (1);
		free(out_cont->filepath);
		out_cont->filepath = ft_strdup(new_filename);
		free(new_filename);
		iter = iter->next;
	}
	return (0);
}

static int	input_redir_var_subst(t_globvar *g_var)
{
	char				*new_filename;

	if (!g_var->redir.input_filepath)
		return (0);
	new_filename = var_subst(g_var->redir.input_filepath, g_var);
	if (!new_filename)
		return (1);
	free(g_var->redir.input_filepath);
	g_var->redir.input_filepath = ft_strdup(new_filename);
	if (!g_var->redir.input_filepath)
		return (1);
	free(new_filename);
	return (0);
}

static int	here_var_subst(t_globvar *g_var)
{
	t_heredoc	*heredoc;
	char		*new_input;

	if (!g_var->here.lst_track)
		return (0);
	heredoc = (t_heredoc *)(g_var->here.lst_track->content);
	if (!heredoc->input)
		return (0);
	new_input = var_subst(heredoc->input, g_var);
	if (!new_input)
		return (1);
	free(heredoc->input);
	heredoc->input = ft_strdup(new_input);
	if (!heredoc->input)
		return (1);
	free(new_input);
	return (0);
}

int	var_subst_redirs(t_globvar *g_var)
{
	if (input_redir_var_subst(g_var))
		return (1);
	if (output_redir_var_subst(g_var))
		return (1);
	if (here_var_subst(g_var))
		return (1);
	return (0);
}
