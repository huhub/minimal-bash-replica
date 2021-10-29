#include "heredoc.h"

void	del_heredoc(void *content)
{
	t_heredoc	*heredoc;

	heredoc = (t_heredoc *)content;
	free(heredoc->keyword);
	if (heredoc->input)
		free(heredoc->input);
	free(heredoc);
	return ;
}

int	add_heredoc(t_list **lst, char *keyword)
{
	t_heredoc	*heredoc;

	heredoc = malloc(sizeof(t_heredoc));
	if (!heredoc)
		return (1);
	heredoc->keyword = ft_strdup(keyword);
	heredoc->input = 0;
	if (!(*lst))
		*lst = ft_lstnew(heredoc);
	else
		ft_lstadd_back(lst, ft_lstnew(heredoc));
	return (0);
}

int	join_here_input(char **dst, char const *input)
{
	if (ft_append(dst, input))
		return (1);
	if (ft_append(dst, "\n"))
		return (1);
	return (0);
}

char	*get_next_heredoc(char const *input)
{
	char	*target;
	int		skip;

	target = (char *)input;
	skip = 0;
	while (1)
	{
		target = mod_strchr(target + skip, '<');
		if (!target)
			break ;
		if (target[1] == '<')
			return (target + 2);
		if (!skip)
			skip = 1;
	}
	return (0);
}
