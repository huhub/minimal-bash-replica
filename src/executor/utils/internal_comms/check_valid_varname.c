#include "../i_comms_utils.h"

int	check_valid_varname(char const *name)
{
	size_t	i;

	if (ft_isdigit(*name))
		return (1);
	i = 0;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (1);
		++i;
	}
	return (0);
}
