#include "../services.h"

static void	skip_spaces(char const *input, size_t *len)
{
	while (input[*len] == ' ')
		*len += 1;
}

static int	check_empty(char const *input)
{
	size_t	i;

	i = 0;
	skip_spaces(input, &i);
	if (!input[i])
		return (1);
	if (input[i] && input[i] != ' ' && input[i] != '|' && input[i] != '\n')
		return (0);
	return (1);
}

int	pipe_validator(char const *input)
{
	char	*target;

	target = (char *)input;
	if (*target == '|')
		return (1);
	while (1)
	{
		target = mod_strchr(target, '|');
		if (!target)
			return (0);
		++target;
		if (check_empty(target))
			return (1);
	}
}
