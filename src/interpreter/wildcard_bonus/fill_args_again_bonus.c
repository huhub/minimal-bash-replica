#include "wildcard_bonus.h"

static int	second_args_fill(char **args, char **aux, size_t const needle,
size_t i)
{
	size_t	j;

	j = needle + 1;
	while (aux[j])
	{
		args[i] = ft_strdup(aux[j]);
		if (!args[i])
			return (1);
		++j;
		++i;
	}
	return (0);
}

static int	new_args_fill(char **args, char **n_args, size_t *i,
size_t *j)
{
	*j = 0;
	while (n_args[*j])
	{
		args[*i] = ft_strdup(n_args[*j]);
		if (!(args[*i]))
			return (1);
		*j += 1;
		*i += 1;
	}	
	return (0);
}

static int	first_aux_fill(char **args, char **aux, size_t *i,
size_t const needle)
{
	*i = 0;
	while (*i < needle)
	{
		args[*i] = ft_strdup(aux[*i]);
		if (!(args[*i]))
			return (1);
		*i += 1;
	}
	return (0);
}

int	fill_args_again(char ***args, char **n_args,
char **aux, size_t const needle)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = two_dim_len(aux) + two_dim_len(n_args) - 1;
	i = 0;
	j = 0;
	*args = malloc(sizeof(char *) * (len + 1));
	if (!(*args))
		return (1);
	(*args)[len] = 0;
	if (first_aux_fill(*args, aux, &i, needle))
		return (1);
	if (new_args_fill(*args, n_args, &i, &j))
		return (1);
	if (second_args_fill(*args, aux, needle, i))
		return (1);
	return (0);
}
