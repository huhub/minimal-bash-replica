#include "reader.h"
#include <readline/readline.h>
#include <readline/history.h>

static void	next_heredoc(t_globvar *g_var)
{
	printf("Bad heredoc ending. Wanted: %s\n",
		((t_heredoc *)g_var->here.lst_track->content)->keyword);
	if (g_var->prov_input)
	{
		((t_heredoc *)(g_var->here.lst_track->content))->input
			= ft_strdup(g_var->prov_input);
		free(g_var->prov_input);
		g_var->prov_input = 0;
	}
	g_var->here.lst_track = g_var->here.lst_track->next;
}

static int	no_input(t_globvar *g_var, t_read_data *rdata)
{
	if (g_var->here.lst)
	{
		next_heredoc(g_var);
		if (!g_var->here.lst_track)
		{
			if (process_final_heredoc(rdata, g_var))
			{
				free_read_data(rdata);
				return (1);
			}
			free_read_data(rdata);
			return (0);
		}
	}
	else
	{
		free_read_data(rdata);
		write(STDOUT_FILENO, "exit\n", 5);
		return (0);
	}
	return (-1);
}

static int	got_input(t_globvar *g_var, t_read_data *rdata)
{
	if (process_input(rdata, g_var))
	{
		free_read_data(rdata);
		return (1);
	}
	return (0);
}

static int	exit_reader(int const exit_code)
{
	rl_clear_history();
	return (exit_code);
}

int	reader(t_globvar *g_var)
{
	t_read_data	rdata;
	int			exit_code;

	init_read_data(&rdata);
	while (!g_var->exit_command)
	{
		if (call_readline(g_var->prompt, &rdata.input))
			return (1);
		if (!rdata.input)
		{
			exit_code = no_input(g_var, &rdata);
			if (!exit_code || exit_code == 1)
				return (exit_reader(exit_code));
		}
		else if (*rdata.input)
		{
			if (got_input(g_var, &rdata))
				return (1);
		}
		free(rdata.input);
		rdata.input = 0;
	}
	rl_clear_history();
	return (0);
}
