#include "../../src/interpreter/interpreter.h"
#include <assert.h>

void	mix(t_globvar *g_var)
{
	int		result;
	char	*comm_no_redir;

	result = 0;
	comm_no_redir = 0;
	result = extract_redirs("echo hola '   > hola.txt   'que tal estas << HEY yo bien <input.txt y tu>> append.txt que tal?", &comm_no_redir, g_var);
	assert(!result && "echo hola '   > hola.txt   'que tal estas << HEY yo bien <input.txt y tu>> append.txt que tal?");
	assert(!ft_strcmp(comm_no_redir, "echo hola '   > hola.txt   'que tal estas  yo bien  y tu que tal?"));
	assert(g_var->redir.input_filepath);
	assert(!ft_strcmp(g_var->redir.input_filepath, "input.txt"));
	assert(g_var->redir.output_queue);
	assert(!ft_strcmp(((t_output_content *)g_var->redir.output_queue->content)->filepath, "append.txt"));
	assert(((t_output_content *)g_var->redir.output_queue->content)->append == 1);
	free(comm_no_redir);
	free_redir(&g_var->redir);
}

int	main(void)
{
	t_globvar	g_var;

	g_var.redir.input_filepath = 0;
	g_var.redir.output_queue = 0;
	g_var.here.lst = 0;
	mix(&g_var);
	return (0);
}
