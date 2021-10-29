#ifndef WILDCARD_BONUS_H
# define WILDCARD_BONUS_H

# include "../interpreter.h"

typedef struct s_cond_content
{
	int		head;
	int		tail;
	char	*str;
}				t_cond_content;

/*
**	wildcard_bonus.c
*/

int		wildcard(char **word);

/*
**	find_matches_bonus.c
*/

int		find_matches(t_list *files, t_list *cond_lst, t_list **matches);

/*
**	file_utils_bonus.c
*/

void	del_file(void *content);
void	add_file(t_list **files, char *filename);
void	get_dir_files(t_list **files);

/*
**	condition_bonus.c
*/

void	del_cond_content(void *content);
int		get_cond_lst(t_list **cond_lst, char const *wildcard);

/*
**	coincidences_bonus.c
*/

int		get_coincidences(char **coincidences, t_list *cond_lst);

/*
**	parser_utils_bonus.c
*/

int		check_modified(char *arg, char ***n_args);
int		modify_args(char ***args, char **n_args, size_t i);
size_t	two_dim_len(char **two_s);

/*
**	fill_args_again.c
*/

int		fill_args_again(char ***args, char **n_args,
			char **aux, size_t const needle);

#endif
