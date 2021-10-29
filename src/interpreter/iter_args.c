#include "interpreter.h"

int	iter_args(char **args, int (*f)(const char *, char **),
t_globvar *g_var)
{
	char	*new_value;
	size_t	i;

	new_value = 0;
	i = 0;
	g_var->empty_command = 0;
	if (ft_strlen(args[i]) == 2 && (args[i][0] == '\'' || args[i][0] == '"'))
		g_var->empty_command = 1;
	while (args[i])
	{
		if (f(args[i], &new_value))
			return (1);
		if (new_value)
		{
			free(args[i]);
			args[i] = ft_strdup(new_value);
			free(new_value);
			new_value = 0;
		}		
		++i;
	}
	return (0);
}
