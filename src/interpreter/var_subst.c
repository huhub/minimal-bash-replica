#include "interpreter.h"

static char	*ft_strchr_count(const char *s, int c, size_t *count)
{
	*count = 0;
	while (*(s + *count))
	{
		if (s[*count] == '\'')
			single_quote((char *)s, count);
		else if (*(char *)(s + *count) == (char)c)
		{
			if (c == '$')
			{
				if (*(s + *count + 1) && *(s + *count + 1) != ' ')
					return ((char *)(s + *count));
			}
			else
				return ((char *)(s + *count));
		}
		*count += 1;
	}
	if ((char)c == 0)
		return ((char *)(s + *count));
	return (0);
}

static size_t	get_var_len(char const *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '?')
			return (1);
		if (!ft_isalnum(str[i]) && str[i] != '_')
			break ;
		i++;
	}
	return (i);
}

static void	append_middle(char **tmp, char **nstr, t_globvar *g_var)
{
	if (!ft_strcmp("?", *tmp))
	{
		free(*tmp);
		*tmp = ft_itoa(g_var->last_exit_code);
		ft_append(nstr, *tmp);
	}
	else
		ft_append(nstr, get_value(*tmp, g_var->envp));
}

static char	*replace(char const *str, t_globvar *g_var)
{
	size_t	first;
	size_t	middle;
	char	*nstr;
	char	*tmp;

	nstr = 0;
	ft_strchr_count(str, '$', &first);
	tmp = ft_substr(str, 0, first);
	ft_append(&nstr, tmp);
	free(tmp);
	middle = get_var_len(str + first + 1);
	if (middle)
	{
		tmp = ft_substr(str, first + 1, middle);
		append_middle(&tmp, &nstr, g_var);
		free(tmp);
	}
	tmp = ft_substr(str, first + middle + 1, ft_strlen(str));
	if (ft_append(&nstr, tmp))
		return (0);
	free(tmp);
	return (nstr);
}

char	*var_subst(char const *str, t_globvar *g_var)
{
	char	*nstr;
	char	*aux;
	size_t	useless;

	if (!str)
		return (0);
	nstr = ft_strdup(str);
	while (ft_strchr_count(nstr, '$', &useless))
	{
		aux = ft_strdup(nstr);
		free(nstr);
		nstr = replace(aux, g_var);
		free(aux);
		if (!nstr)
			return (0);
	}
	return (nstr);
}
