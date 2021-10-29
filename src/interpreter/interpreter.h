#ifndef INTERPRETER_H
# define INTERPRETER_H

# include "../utils/utils.h"
# include "../services/services.h"
# include "../executor/executor.h"

# ifndef NO_BONUS
#  include "wildcard_bonus/wildcard_bonus.h"
# endif

typedef struct s_extract_data
{
	size_t	chunk_start;
	size_t	redir_len;
	size_t	inc;
	size_t	i;
}				t_extract_data;

/*
**	divider.c
*/

int		divider(char const *input, t_globvar *g_var);

/*
**	parser.c
*/

int		parser(char const *comm, int const next, t_globvar *g_var);

/*
**	extract_redirs.c
*/

int		extract_redirs(char const *comm, char **comm_no_redir,
			t_globvar *g_var);

/*
**	extract_redirs_utils.c
*/

void	skip_spaces(char const *input, size_t *len);
char	*get_filename(char const *input);
size_t	get_redir_len(char const *input);
int		cut_and_append(size_t const start, size_t const end,
			char const *input, char **dst);

/*
**	input_output_redirs.c
*/

int		input_redir(char const *comm, t_extract_data *xdata,
			t_globvar *g_var);
int		output_redir(char const *comm, t_extract_data *xdata,
			t_globvar *g_var);

/*
**	space remover.c
*/

int		space_remover(char const *comm, char **new_comm);

/*
**	space_remover_utils.c
*/

int		append_word(char **dst, char const *word,
			char const *input, size_t const counter);

/*
**	set_pipes.c
*/

int		set_pipes(int const next, t_globvar **g_var);

/*
**	var_subst.c
*/

char	*var_subst(char const *str, t_globvar *g_var);

/*
**	var_subst_redirs.c
*/

int		var_subst_redirs(t_globvar *g_var);

/*
**	iter_args.c
*/

int		iter_args(char **args, int (*f)(const char *, char **),
			t_globvar *g_var);

/*
**	waiter.c
*/

int		waiter(t_globvar *g_var, t_list *s_pipes);

#endif
