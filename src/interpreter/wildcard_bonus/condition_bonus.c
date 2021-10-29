#include "wildcard_bonus.h"

void	del_cond_content(void *content)
{
	t_cond_content	*cond_content;

	cond_content = (t_cond_content *)content;
	if (cond_content->str)
		free(cond_content->str);
	free(cond_content);
	return ;
}

static int	add_condition(t_list **lst, char const *condition)
{
	t_cond_content	*content;

	content = malloc(sizeof(t_cond_content));
	if (!content)
		return (1);
	content->head = 0;
	content->tail = 0;
	content->str = ft_strdup(condition);
	if (!content->str)
		return (1);
	if (*lst)
		ft_lstadd_back(lst, ft_lstnew(content));
	else
		*lst = ft_lstnew(content);
	return (0);
}

static int	get_condition(char const *src, char **condition, size_t *i)
{
	char	*end;
	size_t	len;

	end = mod_strchr(src, '*');
	if (!end)
		len = ft_strlen(src);
	else
		len = end - src;
	if (!len)
	{
		*i += 1;
		return (0);
	}
	*condition = ft_substr(src, 0, len);
	if (!(*condition))
		return (1);
	*i += len;
	return (0);
}

int	get_cond_lst(t_list **cond_lst, char const *wildcard)
{
	char	*condition;
	size_t	i;

	condition = 0;
	i = 0;
	while (wildcard[i])
	{
		if (get_condition(&wildcard[i], &condition, &i))
			return (1);
		if (condition)
		{
			if (add_condition(cond_lst, condition))
				return (1);
			free(condition);
			condition = 0;
		}
	}
	if (wildcard[0] != '*')
		((t_cond_content *)((*cond_lst)->content))->head = 1;
	if (wildcard[ft_strlen(wildcard) - 1] != '*')
		((t_cond_content *)(ft_lstlast(*cond_lst))->content)->tail = 1;
	return (0);
}
