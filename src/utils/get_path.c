#include "utils.h"
#include <dirent.h>
#include <errno.h>

struct dirent	*get_directory_entry(char const *target_dir,
char const *target)
{
	DIR				*dir;
	struct dirent	*dir_entry;

	dir = opendir(target_dir);
	if (!dir)
		return (0);
	errno = 0;
	while (1)
	{
		dir_entry = readdir(dir);
		if (!dir_entry)
			break ;
		if (ft_strcmp(dir_entry->d_name, target) == 0)
			break ;
	}
	if (errno)
		printf("readdir");
	if (closedir(dir) == -1)
		return (0);
	return (dir_entry);
}

char	*get_path(char const *filename, t_globvar *g_var)
{
	char	*path;
	char	*sys_path;
	char	**path_list;
	size_t	i;

	path = 0;
	sys_path = get_value("PATH", g_var->envp);
	path_list = ft_split(sys_path, ':');
	if (!path_list)
		return (0);
	i = 0;
	while (path_list[i])
	{
		if (get_directory_entry(path_list[i], filename))
		{
			path = ft_strdup(path_list[i]);
			break ;
		}
		++i;
	}
	free_2dim_str(path_list);
	return (path);
}
