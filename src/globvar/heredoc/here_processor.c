#include "heredoc.h"

static char	*get_keyword(char const *start)
{
	char	*keyword;
	size_t	len;

	len = 0;
	if (start[len] == ' ')
	{
		while (start[len] && start[len] == ' ')
			++len;
	}
	if (!start[len])
		return (0);
	while (start[len] && start[len] != ' ' && start[len] != '<'
		&& start[len] != '>' && start[len] != '|' && start[len] != '\n')
		++len;
	if (start[len] == ' ')
	{
		while (start[len] && start[len] == ' ')
			++len;
	}
	keyword = ft_substr(start, 0, len);
	return (keyword);
}

int	here_processor(char const *input, t_list **here_lst)
{
	char	*start;
	char	*keyword;
	char	*clean_keyword;

	start = (char *)input;
	while (1)
	{
		start = get_next_heredoc(start);
		if (!start)
			return (0);
		keyword = get_keyword(start);
		if (!keyword)
			return (1);
		clean_keyword = ft_strtrim(keyword, " ");
		if (!clean_keyword)
		{
			free(keyword);
			return (1);
		}
		free(keyword);
		if (add_heredoc(here_lst, clean_keyword))
			return (1);
		free(clean_keyword);
	}
}
