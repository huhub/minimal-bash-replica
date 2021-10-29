#ifndef SERVICES_H
# define SERVICES_H

# include <stdio.h>
# include "../utils/utils.h"

/*
**	quotes/quotes.c
*/

size_t	single_quote(const char *str, size_t *inc);
size_t	double_quote(const char *str, size_t *inc);

/*
**	validate/validate_input.c
*/

int		validate_input(const char *final_input);

/*
**	validate/characters.c
*/

size_t	invalid_major_minor(const char *str, size_t *inc);

/*
**	validate/validate_redir_filenames.c
*/

int		validate_redir_filenames(char const *input);

/*
**	validate/pipe_validator.c
*/

int		pipe_validator(char const *input);

#endif
