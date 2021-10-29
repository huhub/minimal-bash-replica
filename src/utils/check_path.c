#include "utils.h"

int	check_path(char const *filename)
{
	if (*filename == '/' || (*filename == '.' && filename[1] == '/')
		|| ft_strchr(filename, '/'))
		return (1);
	return (0);
}
