#include "interpreter.h"

static void	set_space(int *add_space, char const *input, size_t const counter)
{
	if (((input[counter] == '"' || input[counter] == '\'')
			&& (counter == 0 || input[counter - 1] != ' '))
		|| counter == 0 || input[counter - 1] == '"'
		|| input[counter - 1] == '\'')
		*add_space = 0;
}

int	append_word(char **dst, char const *word,
char const *input, size_t const counter)
{
	int	add_space;

	add_space = 1;
	set_space(&add_space, input, counter);
	if (*dst)
	{
		if (add_space)
		{
			if (ft_append(dst, " "))
				return (1);
		}
		if (word)
		{
			if (ft_append(dst, word))
				return (1);
		}
	}
	else if (word)
		*dst = ft_strdup(word);
	else
		*dst = ft_strdup("");
	return (0);
}
