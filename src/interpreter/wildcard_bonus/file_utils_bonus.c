#include "wildcard_bonus.h"
#include <dirent.h>
#include <errno.h>

void	del_file(void *content)
{
	char	*filename;

	filename = (char *)content;
	free(filename);
	return ;
}

void	add_file(t_list **files, char *filename)
{
	char	*name;

	name = ft_strdup(filename);
	if (!(*files))
		*files = ft_lstnew(name);
	else
		ft_lstadd_back(files, ft_lstnew(name));
}

void	get_dir_files(t_list **files)
{
	DIR				*dir;
	struct dirent	*dir_entry;
	char			*curr_dir;

	curr_dir = getcwd(0, 0);
	dir = opendir(curr_dir);
	if (!dir)
		return ;
	free(curr_dir);
	errno = 0;
	while (1)
	{
		dir_entry = readdir(dir);
		if (!dir_entry)
			break ;
		add_file(files, dir_entry->d_name);
	}
	if (errno)
		perror("readdir");
	closedir(dir);
	return ;
}
