#include "internal_comms.h"

char	**split_var(char const *assignment)
{
	char	**res;
	char	*needle;
	size_t	diff;

	res = 0;
	needle = mod_strchr(assignment, '=');
	if (!needle)
		res = ft_split(assignment, '=');
	else
	{
		res = malloc(sizeof(char *) * 3);
		if (!res)
			return (0);
		res[2] = 0;
		diff = needle - assignment;
		res[0] = ft_substr(assignment, 0, diff);
		if (!res[0])
			return (0);
		res[1] = ft_substr(assignment, diff + 1,
				ft_strlen(assignment) - diff - 1);
		if (!res[0])
			return (0);
	}
	return (res);
}
