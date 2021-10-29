#include "wildcard_bonus.h"

static int	middle_condition(char const *condition, char const *name,
char *needle, size_t const c_len)
{
	if (needle)
		needle = ft_strnstr(needle, condition, ft_strlen(needle));
	else
		needle = ft_strnstr(name, condition, ft_strlen(name));
	if (!needle || ft_strlen(name) == ft_strlen(needle)
		|| ft_strlen(condition) == ft_strlen(needle))
		return (1);
	needle += c_len;
	return (0);
}

static int	pass_condition(t_cond_content *condition, char const *name,
char *needle)
{
	size_t	c_len;

	c_len = ft_strlen(condition->str);
	if (condition->head)
	{
		if (ft_strncmp(condition->str, name, c_len))
			return (0);
	}
	else if (condition->tail)
	{
		if (c_len > ft_strlen(name)
			||ft_strncmp(condition->str, &name[ft_strlen(name) - c_len], c_len))
			return (0);
	}
	else
	{
		if (middle_condition(condition->str, name, needle, c_len))
			return (0);
	}
	return (1);
}

static int	is_match(t_list *cond_lst, char *name)
{
	t_list			*c_iter;
	t_cond_content	*condition;
	char			*needle;

	c_iter = cond_lst;
	needle = 0;
	while (c_iter)
	{
		condition = (t_cond_content *)c_iter->content;
		if (!pass_condition(condition, name, needle))
			return (0);
		c_iter = c_iter->next;
	}
	return (1);
}

int	find_matches(t_list *files, t_list *cond_lst, t_list **matches)
{
	t_list	*f_iter;
	char	*name;

	f_iter = files;
	while (f_iter)
	{
		name = (char *)f_iter->content;
		if (is_match(cond_lst, name))
			add_file(matches, name);
		f_iter = f_iter->next;
	}
	return (0);
}
