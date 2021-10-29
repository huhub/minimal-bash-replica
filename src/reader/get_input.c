#include "reader.h"

static void	fill_input(int const res, char *aux, char **input)
{
	if (!res)
	{
		if (aux)
		{
			if (aux[0] == '\n' && !aux[1])
				*input = ft_strdup("");
			else
				*input = ft_strdup(aux);
			free(aux);
		}
	}
}

int	get_input(int fd, char **input)
{
	char	*buff;
	char	*aux;
	int		res;

	buff = malloc(sizeof(char) * (50 + 1));
	if (!buff)
		return (1);
	aux = 0;
	while (1)
	{
		res = read(fd, buff, 50);
		if (res == -1 || !res)
			break ;
		buff[res] = 0;
		if (ft_append(&aux, buff))
			return (1);
	}
	free(buff);
	fill_input(res, aux, input);
	return (res);
}
