#ifndef GLOBVAR_H
# define GLOBVAR_H

# include "../libft/libft.h"
# include "heredoc/heredoc.h"
# include "redir/redir.h"
# include "../controllers/crud/crud.h"
# include <sys/types.h>

# define NORMAL_PROMPT "Prompt:$ "
# define HEREDOC_PROMPT "> "

typedef struct s_heredoc
{
	char	*keyword;
	char	*input;
}				t_heredoc;

typedef struct s_here
{
	t_list	*lst;
	t_list	*lst_track;
	int		here_pipe[2];
}				t_here;

typedef struct s_pipe
{
	int		read[2];
	int		write[2];
	pid_t	pid;
	int		last;
}				t_pipe;

typedef struct s_globvar
{
	int			exit_command;
	int			last_exit_code;
	int			exec;
	int			empty_command;
	t_list		*pipes;
	int			next_read[2];
	t_redir		redir;
	t_here		here;
	char		*prov_input;
	char		*prompt;
	t_list_crud	*envp;
	char		**envp_exec;
	char		**argv;
}				t_globvar;

extern t_globvar	g_var;

/*
**	globvar.c
*/

void	init_globvar(void);
void	init_globvar_interr(void);
void	free_globvar(void);
void	free_globvar_interr(void);

#endif
