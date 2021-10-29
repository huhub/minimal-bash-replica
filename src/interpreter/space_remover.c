#include "interpreter.h"

static size_t	get_len(char const *input)
{
	size_t	len;

	len = 0;
	if (input[len] == '"')
	{
		++len;
		while (input[len] != '"')
			++len;
		++len;
	}
	else if (input[len] == '\'')
	{
		++len;
		while (input[len] != '\'')
			++len;
		++len;
	}
	else
	{
		while (input[len] && input[len] != ' '
			&& input[len] != '"' && input[len] != '\'')
			++len;
	}	
	return (len);
}

static int	get_word(char const *comm, char **new_comm,
char **word, size_t len)
{
	if ((*comm == '"' || *comm == '\'') && len > 2)
	{
		*word = ft_substr(&(*(comm + 1)), 0, len - 2);
		if (!(*word))
		{
			if (*new_comm)
				free(*new_comm);
			return (1);
		}
	}
	else if (*comm != '"' && *comm != '\'')
	{
		*word = ft_substr(&(*comm), 0, len);
		if (!(*word))
		{
			if (*new_comm)
				free(*new_comm);
			return (1);
		}
	}
	return (0);
}

static int	clean_exit(char **new_comm, char *word)
{
	if (*new_comm)
		free(*new_comm);
	free(word);
	return (1);
}

int	space_remover(char const *comm, char **new_comm)
{
	char	*word;
	size_t	len;
	size_t	i;

	word = 0;
	len = 0;
	i = 0;
	while (comm[i])
	{
		if (comm[i] != ' ')
		{
			len = get_len(&comm[i]);
			if (get_word(&comm[i], new_comm, &word, len))
				return (1);
			if (append_word(new_comm, word, comm, i))
				return (clean_exit(new_comm, word));
			free(word);
			word = 0;
			i += len - 1;
		}
		++i;
	}
	return (0);
}
