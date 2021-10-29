#include "reader.h"
#include <readline/readline.h>
#include <readline/history.h>

void	delete_here_lst(t_globvar *g_var)
{
	if (g_var->here.lst)
	{
		g_var->here.lst_track = g_var->here.lst;
		while (g_var->here.lst_track)
			g_var->here.lst_track = g_var->here.lst_track->next;
		ft_lstclear(&g_var->here.lst, del_heredoc);
	}
}

int	process_final_heredoc(t_read_data *rdata, t_globvar *g_var)
{
	free(rdata->input);
	rdata->input = rdata->first_input;
	rdata->first_input = 0;
	if (divider(rdata->input, g_var))
	{
		delete_here_lst(g_var);
		return (1);
	}
	delete_here_lst(g_var);
	g_var->prompt = NORMAL_PROMPT;
	return (0);
}

static int	heredoc_input(t_read_data *rdata, t_globvar *g_var)
{
	if (!ft_strcmp(rdata->input,
			((t_heredoc *)(g_var->here.lst_track->content))->keyword))
	{
		if (g_var->prov_input)
		{
			((t_heredoc *)(g_var->here.lst_track->content))->input
				= ft_strdup(g_var->prov_input);
			free(g_var->prov_input);
			g_var->prov_input = 0;
		}
		g_var->here.lst_track = g_var->here.lst_track->next;
		if (!g_var->here.lst_track)
		{
			if (process_final_heredoc(rdata, g_var))
				return (1);
		}
	}
	else
	{
		if (join_here_input(&g_var->prov_input, rdata->input))
			return (1);
	}
	return (0);
}

/*
**	LA FUNCIÓN DE REVISIÓN DE SINTAXIS YA HA REVISADO
**	SI HAY MÁS DE DOS < Ó > SEGUIDOS.
*/

static int	unknown_input(t_read_data *rdata, t_globvar *g_var)
{
	add_history(rdata->input);
	if (get_next_heredoc(rdata->input))
	{
		if (here_processor(rdata->input, &g_var->here.lst))
			return (1);
		g_var->here.lst_track = g_var->here.lst;
		g_var->prompt = HEREDOC_PROMPT;
		rdata->first_input = ft_strdup(rdata->input);
	}
	else
	{
		if (divider(rdata->input, g_var))
			return (1);
	}
	return (0);
}

int	process_input(t_read_data *rdata, t_globvar *g_var)
{
	if (!g_var->here.lst)
	{
		if (validate_input(rdata->input))
		{
			custom_err_msg("syntax error\n");
			return (0);
		}
		if (unknown_input(rdata, g_var))
			return (1);
	}
	else
		if (heredoc_input(rdata, g_var))
			return (1);
	return (0);
}
