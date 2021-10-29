#include "../../src/interpreter/interpreter.h"
#include <assert.h>

static void	no_quotes(t_globvar *g_var)
{
	char	*res;

	res = 0;
	res = var_subst("Hola $USER como estas.", g_var);
	assert(!ft_strcmp(res, "Hola anonymous como estas.")
			&& "Hola $USER como estas.");
	free(res);
	res = var_subst("Hola $BAD como estas.", g_var);
	assert(!ft_strcmp(res, "Hola  como estas.")
			&& "Hola $BAD como estas.");
	free(res);
	res = var_subst("Hola $ como estas.", g_var);
	assert(!ft_strcmp(res, "Hola $ como estas.")
			&& "Hola $ como estas.");
	free(res);
	res = var_subst("$USER como estas.", g_var);
	assert(!ft_strcmp(res, "anonymous como estas.")
			&& "$USER como estas.");
	free(res);
	res = var_subst("Mi nombre es $USER", g_var);
	assert(!ft_strcmp(res, "Mi nombre es anonymous")
			&& "Mi nombre es $USER");
	free(res);
	res = var_subst("$USER", g_var);
	assert(!ft_strcmp(res, "anonymous") && "$USER");
	free(res);
}

static void	single_quotes(t_globvar *g_var)
{
	char	*res;

	res = 0;
	res = var_subst("Hola '$USER' como estas.", g_var);
	assert(!ft_strcmp(res, "Hola '$USER' como estas.")
			&& "Hola '$USER' como estas.");
	free(res);
}

static void	double_quotes(t_globvar *g_var)
{
	char	*res;

	res = 0;
	res = var_subst("Hola \"$USER\" como estas.", g_var);
	assert(!ft_strcmp(res, "Hola \"anonymous\" como estas.")
			&& "Hola \"$USER\" como estas.");
	free(res);
}

int	main(void)
{
	t_globvar	g_var;

	g_var.envp = get_new_list();
	add_crud(g_var.envp, "USER", "anonymous");
	add_crud(g_var.envp, "HOME", "Planet Mars");
	no_quotes(&g_var);
	single_quotes(&g_var);
	double_quotes(&g_var);
	free_list_crud(&g_var.envp);
	return (0);
}
