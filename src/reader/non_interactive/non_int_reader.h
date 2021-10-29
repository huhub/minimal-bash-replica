#ifndef NON_INT_READER_H
# define NON_INT_READER_H

# include "../reader.h"

# define BUFFER_SIZE 256

/*
**	gnl.c
*/

int		get_next_line(int fd, char **line);

/*
**	gnl_utils.c
*/

char	*ft_get_after_line(char *s);

/*
** non_int_reader.c
*/

int		non_int_reader(char *filename, t_globvar *g_var);

#endif
