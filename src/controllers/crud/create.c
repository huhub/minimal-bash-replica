#include "crud.h"
#include "../../utils/utils.h"

/*
**	enlazar nueva lista ligada
*/

t_list_crud	*get_new_list(void)
{
	t_list_crud		*ll;

	ll = (t_list_crud *)malloc(sizeof(t_list_crud));
	ll->size = 0;
	ll->first_item = NULL;
	ll->last_item = NULL;
	return (ll);
}

t_node	*get_node(char *command, char *value)
{
	t_node			*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->command = ft_strdup(command);
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = ft_strdup("");
	node->next = NULL;
	return (node);
}

/*
**	Add element to list
*/

void	add_crud(t_list_crud *ll, char *command, char *str)
{
	t_node		*node;

	node = get_node(command, str);
	if (ll->first_item == NULL)
		ll->first_item = node;
	else
		ll->last_item->next = node;
	ll->last_item = node;
	ll->size++;
}
