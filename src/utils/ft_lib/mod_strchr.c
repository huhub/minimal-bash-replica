#include "../utils.h"

char	*mod_strchr(const char *s, int c)
{
	size_t	count;

	if (!s || !c)
		return (0);
	count = 0;
	while (*(s + count))
	{
		if (s[count] == '"')
			double_quote((char *)s, &count);
		else if (s[count] == '\'')
			single_quote((char *)s, &count);
		else if (*(char *)(s + count) == (char)c)
			return ((char *)(s + count));
		count++;
	}
	if ((char)c == 0)
		return ((char *)(s + count));
	return (0);
}
