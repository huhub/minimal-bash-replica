#include "crud.h"
#include "../../utils/utils.h"

/**
 * Update a element of list according to index
 */

void	update(t_list_crud *ll, unsigned int index, char *newValue)
{
	size_t	i;
	t_node	*list_explorer;

	if (ll->size && index < ll->size)
	{
		list_explorer = ll->first_item;
		i = 0;
		while (i++ < index)
			list_explorer = list_explorer->next;
		free(list_explorer->value);
		if (newValue)
			list_explorer->value = ft_strdup(newValue);
		else
			list_explorer->value = ft_strdup("");
	}
}
