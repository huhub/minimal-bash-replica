#include "interpreter.h"

static void	init_vars(char **aux_1, char **aux_2, char ***args)
{
	*aux_1 = 0;
	*aux_2 = 0;
	*args = 0;
	return ;
}

static int	iter_args_bonus(char ***args, int (*f)(char **), t_globvar *g_var)
{
	char	**n_args;
	size_t	i;

	n_args = 0;
	i = 0;
	while ((*args)[i])
	{
		if (f(&((*args)[i])))
			return (1);
		if (check_modified((*args)[i], &n_args))
		{
			if (modify_args(args, n_args, i))
				return (1);
			i += two_dim_len(n_args) - 1;
		}
		free_2dim_str(n_args);
		++i;
	}
	if (iter_args(*args, space_remover, g_var))
		return (1);
	return (0);
}

static void	free_parser(char *aux_1, char *aux_2, char **args, t_redir *redir)
{
	if (aux_1)
		free(aux_1);
	if (aux_2)
		free(aux_2);
	if (args)
		free_2dim_str(args);
	free_redir(redir);
	return ;
}

static int	failure_exit(char *aux_1, char *aux_2, char **args, t_redir *redir)
{
	free_parser(aux_1, aux_2, args, redir);
	return (1);
}

int	parser(char const *comm, int const next, t_globvar *g_var)
{
	char	*aux_1;
	char	*aux_2;
	char	**args;

	init_vars(&aux_1, &aux_2, &args);
	if (extract_redirs(comm, &aux_1, g_var))
		return (1);
	aux_2 = var_subst(aux_1, g_var);
	if (var_subst_redirs(g_var))
		return (failure_exit(aux_1, aux_2, args, &g_var->redir));
	free(aux_1);
	aux_1 = 0;
	aux_1 = ft_strtrim(aux_2, " ");
	args = ft_splitter(aux_1, ' ');
	if (iter_args_bonus(&args, wildcard, g_var))
		return (failure_exit(aux_1, aux_2, args, &g_var->redir));
	if (set_pipes(next, &g_var))
		return (failure_exit(aux_1, aux_2, args, &g_var->redir));
	if (set_here_pipe(&g_var->here))
		return (failure_exit(aux_1, aux_2, args, &g_var->redir));
	if (executor(args, g_var))
		return (failure_exit(aux_1, aux_2, args, &g_var->redir));
	free_parser(aux_1, aux_2, args, &g_var->redir);
	return (0);
}
