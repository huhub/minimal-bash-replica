#include "crud.h"
#include "../../utils/utils.h"

/**
 * Remove a element of list according to index
 */

static void	next_item(unsigned int index, t_list_crud *ll)
{
	t_node		*aux;
	t_node		*list_explorer;
	size_t		i;

	aux = NULL;
	list_explorer = ll->first_item;
	i = 0;
	while (i++ < index - 1)
		list_explorer = list_explorer->next;
	aux = list_explorer->next;
	if (index == ll->size - 1)
	{
		list_explorer->next = 0;
		ll->last_item = list_explorer;
	}
	else
		list_explorer->next = list_explorer->next->next;
	free(aux->command);
	free(aux->value);
	free(aux);
}

void	removed(t_list_crud *ll, unsigned int index)
{
	t_node		*aux;

	aux = NULL;
	if (ll->size && index < ll->size)
	{
		if (index == 0)
		{
			aux = ll->first_item;
			ll->first_item = ll->first_item->next;
			free(aux->command);
			free(aux->value);
			free(aux);
		}
		else
		{
			next_item(index, ll);
		}
		ll->size--;
	}
}
