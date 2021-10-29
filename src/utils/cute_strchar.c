#include "utils.h"

char	*command_line_var(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && ft_strlen(str) > len)
		len++;
	return (ft_substr(str, 0, len));
}
