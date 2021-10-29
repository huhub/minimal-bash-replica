#include "../services.h"

static void	skip_spaces(char const *input, size_t *len)
{
	while (input[*len] == ' ')
		*len += 1;
}

static int	check_filename(char const *input)
{
	size_t	i;

	i = 0;
	skip_spaces(input, &i);
	if (!input[i])
		return (1);
	if (input[i] && input[i] != ' ' && input[i] != '<'
		&& input[i] != '>' && input[i] != '|' && input[i] != '\n')
		return (0);
	return (1);
}

static int	redir_validator(char const *input, int const redir_sign)
{
	char	*target;

	target = (char *)input;
	while (1)
	{
		target = mod_strchr(target, redir_sign);
		if (!target)
			return (0);
		++target;
		if (*target == redir_sign)
			++target;
		if (check_filename(target))
			return (1);
	}
}

int	validate_redir_filenames(char const *input)
{
	if (redir_validator(input, '<'))
		return (1);
	if (redir_validator(input, '>'))
		return (1);
	return (0);
}
