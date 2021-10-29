#include "../utils.h"

int	ft_append(char **dst, char const *src)
{
	char	*aux;

	if (!dst || !src)
		return (1);
	if (!(*dst))
	{
		*dst = ft_strdup(src);
		return (0);
	}
	aux = ft_strdup(*dst);
	free(*dst);
	*dst = ft_strjoin(aux, src);
	if (!(*dst))
	{
		free(aux);
		return (1);
	}
	free(aux);
	return (0);
}
