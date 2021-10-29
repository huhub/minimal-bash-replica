#include "wildcard_bonus.h"

static int	get_match_array(t_list *matches, char ***m_arr)
{
	size_t	m_arr_len;
	t_list	*iter;
	size_t	i;

	m_arr_len = ft_lstsize(matches);
	*m_arr = malloc(sizeof(char *) * (m_arr_len + 1));
	if (!(*m_arr))
		return (1);
	(*m_arr)[m_arr_len] = 0;
	iter = matches;
	i = 0;
	while (iter)
	{
		(*m_arr)[i] = ft_strdup((char *)iter->content);
		iter = iter->next;
		++i;
	}
	return (0);
}

static int	insert_in_str(char **str, char **filenames)
{
	size_t	i;

	if (ft_append(str, filenames[0]))
		return (1);
	i = 1;
	while (filenames[i])
	{
		ft_append(str, " ");
		if (ft_append(str, filenames[i]))
			return (1);
		++i;
	}	
	return (0);
}

static int	insert_matches(char **coincidences, t_list *matches)
{
	char	**m_arr;
	char	**sort_m_arr;

	m_arr = 0;
	if (get_match_array(matches, &m_arr))
		return (1);
	sort_m_arr = alpha_sort(m_arr, ft_lstsize(matches));
	ft_lstclear(&matches, del_file);
	free_2dim_str(m_arr);
	if (!sort_m_arr)
		return (1);
	if (insert_in_str(coincidences, sort_m_arr))
		return (1);
	free_2dim_str(sort_m_arr);
	return (0);
}

int	get_coincidences(char **coincidences, t_list *cond_lst)
{
	t_list	*files;
	t_list	*matches;

	files = 0;
	matches = 0;
	get_dir_files(&files);
	if (!files)
		return (0);
	if (find_matches(files, cond_lst, &matches))
		return (1);
	ft_lstclear(&files, del_file);
	if (!matches)
		return (0);
	if (insert_matches(coincidences, matches))
		return (1);
	return (0);
}
