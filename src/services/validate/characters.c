#include "../services.h"

size_t	invalid_major_minor(const char *str, size_t *inc)
{
	size_t	count_cases;

	count_cases = 0;
	while (str[*inc])
	{
		if (str[*inc] == '<' && str[*inc + 1] == '>')
			return (3);
		if (str[*inc] == '>' && str[*inc + 1] == '<')
			return (3);
		else if (str[*inc] == '<' || str[*inc] == '>')
			count_cases++;
		else if (str[*inc] != '<' || str[*inc] != '>')
			return (count_cases);
		if (count_cases > 2)
			return (count_cases);
		*inc = *inc + 1;
	}
	return (count_cases);
}
