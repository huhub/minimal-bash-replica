#include "non_int_reader.h"

char	*ft_get_after_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (&s[++i]);
}
