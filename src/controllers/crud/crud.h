#ifndef CRUD_H
# define CRUD_H

# include "../../libft/libft.h"

typedef struct s_node
{
	char			*command;
	char			*value;
	struct s_node	*next;
}					t_node;

typedef struct s_listCrud
{
	size_t			size;
	t_node			*first_item;
	t_node			*last_item;
}					t_list_crud;

t_list_crud	*get_new_list(void);
t_node		*get_node(char *command, char *value);
t_node		*read_crud(t_list_crud *ll, unsigned int index);
void		add_crud(t_list_crud *ll, char *command, char *str);
void		update(t_list_crud *ll, unsigned int index, char *newValue);
void		removed(t_list_crud *ll, unsigned int index);
void		free_list_crud(t_list_crud **list);
char		*get_value(char const *name, t_list_crud *env);
int			find_var(char const *var_name, size_t *index, t_list_crud *envp);

#endif
