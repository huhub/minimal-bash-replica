#ifndef REDIR_H
# define REDIR_H

# include "../../libft/libft.h"

typedef struct s_output_content
{
	char	*filepath;
	int		append;
}				t_output_content;

typedef struct s_redir
{
	char	*input_filepath;
	t_list	*output_queue;
}				t_redir;

/*
**	redir.c
*/

int		get_redir_read_fd(t_redir const *redir, int *fd);
int		get_redir_write_fd(t_redir const *redir, int *fd);
void	free_redir(t_redir *redir);

#endif
