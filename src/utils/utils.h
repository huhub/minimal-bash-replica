#ifndef UTILS_H
# define UTILS_H

# include "../globvar/globvar.h"
# include "../services/services.h"

typedef struct s_globvar	t_globvar;

/*
**	ft_lib/ft_strcmp.c
*/

int				ft_strcmp(char const *a, char const *b);

/*
**	ft_lib/ft_append.c
*/

int				ft_append(char **dst, char const *src);

/*
**	ft_lib/ft_strcmp.c
*/

char			*mod_strchr(const char *s, int c);

/*
**	ft_lib/ft_splitter.c
*/

char			**ft_splitter(char const *input, char const divider);

/*
**	free_2dim_str.c
*/

void			free_2dim_str(char **arr);

/*
**	alpha_sort.c
*/

char			**alpha_sort(char **a, size_t len);

/*
**	get_path.c
*/

char			*get_path(char const *filename, t_globvar *g_var);
struct dirent	*get_directory_entry(char const *target_dir,
					char const *target);

/*
**	check_path.c
*/

int				check_path(char const *filename);

/*
**	custom_err_msg.c
*/

void			custom_err_msg(char *msg);

//

char			*command_line_var(const char *str, char c);
void			concat_str_char(char *str, char c);
void			concat_return(char *return_str, char *str);
void			parameter(t_globvar *g_var, char **argv, char **envp);

#endif
