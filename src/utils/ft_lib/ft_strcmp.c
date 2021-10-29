#include "../utils.h"

int	ft_strcmp(char const *a, char const *b)
{
	size_t	a_len;
	size_t	b_len;
	size_t	max_len;

	a_len = ft_strlen(a);
	b_len = ft_strlen(b);
	if (a_len > b_len)
		max_len = a_len;
	else
		max_len = b_len;
	return (ft_strncmp(a, b, max_len));
}
