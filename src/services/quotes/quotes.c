#include "../services.h"

size_t	single_quote(const char *str, size_t *inc)
{
	size_t	count_queue;

	count_queue = 0;
	while (count_queue < 2 && str[*inc])
	{
		if (str[*inc] == '\'')
			++count_queue;
		*inc = *inc + 1;
	}
	*inc = *inc - 1;
	return (count_queue);
}

size_t	double_quote(const char *str, size_t *inc)
{
	size_t	count_queue;

	count_queue = 0;
	while (count_queue < 2 && str[*inc])
	{
		if (str[*inc] == '"' && str[*inc - 1] != '\\')
			++count_queue;
		*inc = *inc + 1;
	}
	*inc = *inc - 1;
	return (count_queue);
}
