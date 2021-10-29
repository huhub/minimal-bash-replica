#include "interpreter.h"

void	skip_spaces(char const *input, size_t *len)
{
	while (input[*len] == ' ')
		*len += 1;
}

char	*get_filename(char const *input)
{
	char	*filename;
	char	*aux;
	size_t	len;

	filename = 0;
	aux = 0;
	len = 0;
	skip_spaces(input, &len);
	if (!input[len])
		return (0);
	while (input[len] && input[len] != ' ' && input[len] != '<'
		&& input[len] != '>' && input[len] != '|' && input[len] != '\n')
		++len;
	aux = ft_substr(input, 0, len);
	filename = ft_strtrim(aux, " ");
	free(aux);
	return (filename);
}

size_t	get_redir_len(char const *input)
{
	size_t	len;

	len = 0;
	if (input[len] == ' ')
	{
		while (input[len] && input[len] == ' ')
			++len;
	}
	while (input[len] && input[len] != ' ' && input[len] != '<'
		&& input[len] != '>')
		++len;
	if (input[len] == ' ')
	{
		while (input[len] && input[len] == ' ')
			++len;
	}
	return (len);
}

int	cut_and_append(size_t const start, size_t const end,
char const *input, char **dst)
{
	size_t	len;
	char	*chunk;

	len = end - start;
	chunk = ft_substr(input, start, len);
	if (!chunk)
		return (1);
	if (*dst)
	{
		ft_append(dst, " ");
		if (ft_append(dst, chunk))
		{
			free(chunk);
			return (1);
		}
	}
	else
		*dst = ft_strdup(chunk);
	free(chunk);
	return (0);
}
