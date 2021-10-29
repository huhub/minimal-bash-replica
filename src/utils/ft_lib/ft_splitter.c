#include "../utils.h"
#include "../../services/services.h"

static int	comm_counter(char const *input, char divider)
{
	int		commands;
	size_t	i;

	commands = 1;
	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
			double_quote(input, &i);
		if (input[i] == '\'')
			single_quote(input, &i);
		if (input[i] == divider && input[i - 1] != divider)
			commands++;
		i++;
	}	
	return (commands);
}

static int	pos_first_divider(char const *input, char const divider)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
			double_quote(input, &i);
		if (input[i] == '\'')
			single_quote(input, &i);
		if (input[i] == divider && input[i - 1] != divider)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_splitter(char const *input, char const divider)
{
	char	**res;
	int		commands;
	int		command_len;
	int		i;

	commands = comm_counter(input, divider);
	res = malloc(sizeof(char *) * (commands + 1));
	if (!res)
		return (0);
	res[commands] = 0;
	i = 0;
	while (i < commands)
	{
		command_len = pos_first_divider(input, divider);
		res[i] = ft_substr(input, 0, command_len);
		input += command_len + 1;
		i++;
	}
	return (res);
}
