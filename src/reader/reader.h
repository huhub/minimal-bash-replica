#ifndef READER_H
# define READER_H

# include "../libft/libft.h"
# include "../utils/utils.h"
# include "../globvar/globvar.h"
# include "../services/services.h"
# include "../interpreter/interpreter.h"

typedef struct s_read_data
{
	char	*input;
	char	*first_input;
}				t_read_data;

/*
**	process_input.c
*/

void	delete_here_lst(t_globvar *g_var);
int		process_final_heredoc(t_read_data *rdata, t_globvar *g_var);
int		process_input(t_read_data *rdata, t_globvar *g_var);

/*
**	rdata.c
*/

void	free_read_data(t_read_data *rdata);
void	init_read_data(t_read_data *rdata);

/*
**	reader.c
*/

int		reader(t_globvar *g_var);

/*
**	readline MISSING PROTOTYPE
*/

void	rl_clear_history(void);

/*
**	call_readline.c
*/

int		call_readline(char *prompt, char **input);

/*
**	get_input.c
*/

int		get_input(int fd, char **input);

#endif
