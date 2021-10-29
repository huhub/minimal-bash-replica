#include "wildcard_bonus.h"

size_t	two_dim_len(char **two_s)
{
	size_t	i;

	i = 0;
	while (two_s[i])
		++i;
	return (i);
}

static int	copy_old_args(char **args, char ***aux)
{
	size_t	len;
	size_t	i;

	len = two_dim_len(args);
	*aux = malloc(sizeof(char *) * (len + 1));
	if (!(*aux))
		return (1);
	(*aux)[len] = 0;
	i = 0;
	while (args[i])
	{
		(*aux)[i] = ft_strdup(args[i]);
		if (!(*aux)[i])
			return (1);
		++i;
	}	
	return (0);
}

int	modify_args(char ***args, char **n_args, size_t i)
{
	char	**aux;

	aux = 0;
	if (copy_old_args(*args, &aux))
		return (1);
	free_2dim_str(*args);
	*args = 0;
	if (fill_args_again(args, n_args, aux, i))
		return (1);
	free_2dim_str(aux);
	return (0);
}

int	check_modified(char *arg, char ***n_args)
{
	*n_args = ft_splitter(arg, ' ');
	if (!(*n_args))
		return (0);
	if ((*n_args)[1])
		return (1);
	return (0);
}
