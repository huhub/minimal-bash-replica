#include "../services.h"

static void	initial_vars(size_t *count, int *s_quote_var,
	int *d_quote_var, int *here)
{
	*count = 0;
	*s_quote_var = 0;
	*d_quote_var = 0;
	*here = 0;
}

int	validate_input(const char *str)
{
	size_t	count;
	int		s_quote_var;
	int		d_quote_var;
	int		here;

	initial_vars(&count, &s_quote_var, &d_quote_var, &here);
	if (pipe_validator(str) || validate_redir_filenames(str))
		return (1);
	while (str[count])
	{
		if (str[count] == '"')
			d_quote_var += double_quote((char *)str, &count);
		else if (str[count] == '\'')
			s_quote_var += single_quote((char *)str, &count);
		else if (str[count] == '>' || str[count] == '<')
		{
			here = invalid_major_minor((char *)str, &count);
			if (here % 2 != 0)
				break ;
		}
		count++;
	}
	if (d_quote_var % 2 != 0 || s_quote_var % 2 != 0 || here > 2)
		return (1);
	return (0);
}
