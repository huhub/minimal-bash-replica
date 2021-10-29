#include "wildcard_bonus.h"

int	process_wildcard(char **wildcard)
{
	t_list	*cond_lst;
	char	*coincidences;

	cond_lst = 0;
	coincidences = 0;
	if (get_cond_lst(&cond_lst, *wildcard))
		return (1);
	if (get_coincidences(&coincidences, cond_lst))
		return (1);
	if (coincidences)
	{
		free(*wildcard);
		*wildcard = ft_strdup(coincidences);
		free(coincidences);
	}
	ft_lstclear(&cond_lst, del_cond_content);
	return (0);
}

int	wildcard(char **word)
{
	if (mod_strchr(*word, '*'))
	{
		if (process_wildcard(word))
			return (1);
	}
	return (0);
}
