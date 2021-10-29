#include "crud.h"
#include "../../utils/utils.h"

/**
*	Search environment variable to env in list return value
*/

char	*get_value(char const *name, t_list_crud *env)
{
	t_node		*iter;

	iter = env->first_item;
	if (name)
	{
		while (iter)
		{
			if (!ft_strcmp(iter->command, name))
				return (iter->value);
			iter = iter->next;
		}
	}
	return (0);
}
/**
 * Find str in list return index position
 */

int	find_var(char const *var_name, size_t *index, t_list_crud *envp)
{
	t_node	*iter;

	*index = 0;
	iter = envp->first_item;
	while (iter)
	{
		if (!ft_strcmp(iter->command, var_name))
			return (1);
		iter = iter->next;
		*index += 1;
	}
	return (0);
}

/**
* Frees element of list 
*/

void	free_list_crud(t_list_crud **lst)
{
	t_node		*iter;
	t_node		*aux;

	iter = (*lst)->first_item;
	while (iter)
	{
		aux = iter->next;
		free(iter->command);
		free(iter->value);
		free(iter);
		iter = aux;
	}
	free(*lst);
}
