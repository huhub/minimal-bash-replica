#ifndef HEREDOC_H
# define HEREDOC_H

# include "../../utils/utils.h"
# include "../globvar.h"

typedef struct s_here	t_here;

/*
**	here_processor.c
*/

int		here_processor(char const *input, t_list **here_lst);

/*
**	heredoc.c
*/

void	del_heredoc(void *content);
int		add_heredoc(t_list **lst, char *keyword);
int		join_here_input(char **dst, char const *input);
char	*get_next_heredoc(char const *input);

/*
**	here_pipe.c
*/

int		set_here_pipe(t_here *here);
void	close_here_pipe(t_here *here);

#endif
