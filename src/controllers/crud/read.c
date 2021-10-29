#include "crud.h"
#include "../../utils/utils.h"

/**
 * Read a element of list according to index 
 */

t_node	*read_crud(t_list_crud *ll, unsigned int index)
{
	size_t	i;
	t_node	*list_explorer;

	list_explorer = NULL;
	if (ll->size && index < ll->size)
	{
		list_explorer = ll->first_item;
		i = 0;
		while (i++ < index)
			list_explorer = list_explorer->next;
	}
	return (list_explorer);
}
