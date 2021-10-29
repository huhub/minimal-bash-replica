#include "main.h"
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

void	main_sig_handler(int signum)
{
	if (signum == SIGQUIT)
	{
		if (g_var.exec)
			write(1, "Quit\n", 5);
	}
	if (signum == SIGINT)
	{
		if (g_var.exec)
		{
			write(1, "\n", 1);
			return ;
		}
		g_var.last_exit_code = 130;
		free_globvar_interr();
		init_globvar_interr();
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 2)
		return (1);
	init_globvar();
	parameter(&g_var, argv, envp);
	if (argc == 1)
	{
		signal(SIGINT, main_sig_handler);
		signal(SIGTERM, SIG_IGN);
		signal(SIGQUIT, main_sig_handler);
		if (reader(&g_var))
		{
			free_globvar();
			return (1);
		}
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGTERM, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		if (non_int_reader(argv[1], &g_var))
			return (1);
	}
	free_globvar();
	return (g_var.last_exit_code);
}
