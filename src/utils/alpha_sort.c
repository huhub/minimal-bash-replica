#include "utils.h"

static int	swap_str(char **a, char **b)
{
	char	*aux;

	if (!*a || !*b)
		return (1);
	aux = ft_strdup(*a);
	free(*a);
	*a = ft_strdup(*b);
	free(*b);
	*b = ft_strdup(aux);
	free(aux);
	return (0);
}

static int	ordered_fill(char **src, char **dst)
{
	size_t	i;
	size_t	j;

	if (!src || !dst || !src[0])
		return (0);
	i = 0;
	j = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		j = i;
		while (j > 0 && ft_strcmp(dst[j], dst[j - 1]) < 0)
		{
			if (swap_str(&dst[j], &dst[j - 1]))
				return (1);
			--j;
		}
		++i;
	}
	return (0);
}

static int	create_array(char ***res, size_t len)
{
	*res = malloc(sizeof(char *) * (len + 1));
	if (!(*res))
		return (1);
	(*res)[len] = 0;
	return (0);
}

char	**alpha_sort(char **a, size_t len)
{
	char	**res;

	if (create_array(&res, len))
		return (0);
	if (ordered_fill(a, res))
		return (0);
	return (res);
}
