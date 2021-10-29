#include "reader.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

static void	read_sighandler(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

static int	wait_line(pid_t const child)
{
	int	status;

	status = 0;
	if (waitpid(child, &status, 0) == -1)
		return (1);
	if (WIFSIGNALED(status))
		return (1);
	if (WEXITSTATUS(status) != 0)
		return (1);
	return (0);
}

static int	launch_readline(pid_t *child, int pipe_fd[2], char const *prompt)
{
	char	*input;

	*child = fork();
	if (*child == -1)
		return (1);
	if (!(*child))
	{
		signal(SIGINT, read_sighandler);
		signal(SIGQUIT, SIG_IGN);
		close(pipe_fd[0]);
		input = readline(prompt);
		if (!input)
			ft_putstr_fd(0, pipe_fd[1]);
		else if (*input)
			ft_putstr_fd(input, pipe_fd[1]);
		else
			ft_putstr_fd("\n", pipe_fd[1]);
		close(pipe_fd[1]);
		free(input);
		exit(EXIT_SUCCESS);
	}
	else
		return (0);
}

int	call_readline(char *prompt, char **input)
{
	int		pipe_fd[2];
	pid_t	child;

	child = 0;
	while (1)
	{	
		if (pipe(pipe_fd) == -1)
			return (1);
		if (launch_readline(&child, pipe_fd, prompt))
			return (1);
		close(pipe_fd[1]);
		if (!wait_line(child))
			break ;
		close(pipe_fd[0]);
		prompt = "Prompt:$ ";
	}
	if (get_input(pipe_fd[0], input))
		return (1);
	return (0);
}
