#include "globvar.h"

t_globvar	g_var;

void	free_globvar_interr(void)
{
	free_redir(&g_var.redir);
	if (g_var.here.lst)
		ft_lstclear(&g_var.here.lst, del_heredoc);
	if (g_var.prov_input)
		free(g_var.prov_input);
	return ;
}

void	free_globvar(void)
{
	free_redir(&g_var.redir);
	if (g_var.here.lst)
		ft_lstclear(&g_var.here.lst, del_heredoc);
	if (g_var.prov_input)
		free(g_var.prov_input);
	if (g_var.envp)
		free_list_crud(&g_var.envp);
	if (g_var.envp_exec)
		free_2dim_str(g_var.envp_exec);
	return ;
}

void	init_globvar_interr(void)
{
	g_var.redir.input_filepath = 0;
	g_var.redir.output_queue = 0;
	g_var.here.lst = 0;
	g_var.here.lst_track = 0;
	g_var.prov_input = 0;
	g_var.prompt = NORMAL_PROMPT;
	return ;
}

void	init_globvar(void)
{
	g_var.exit_command = 0;
	g_var.last_exit_code = 0;
	g_var.exec = 0;
	g_var.empty_command = 0;
	g_var.pipes = 0;
	g_var.next_read[0] = -1;
	g_var.next_read[1] = -1;
	g_var.redir.input_filepath = 0;
	g_var.redir.output_queue = 0;
	g_var.here.lst = 0;
	g_var.here.lst_track = 0;
	g_var.prov_input = 0;
	g_var.prompt = NORMAL_PROMPT;
	g_var.envp = NULL;
	g_var.envp_exec = 0;
	g_var.argv = NULL;
	return ;
}
