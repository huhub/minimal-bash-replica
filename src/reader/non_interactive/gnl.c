#include "non_int_reader.h"

static char	*ft_get_line(char *s)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] != '\n')
		return (0);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	line[i] = 0;
	j = 0;
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	return (line);
}

static void	ft_save_buffer(char *buffer, char **s_memory, int fd)
{
	char	*aux;

	aux = ft_strjoin(s_memory[fd], buffer);
	free(s_memory[fd]);
	s_memory[fd] = ft_strdup(aux);
	free(aux);
}

static int	ft_line_result(char **s_memory, char **line, int fd)
{
	char	*aux;

	if (ft_strchr(s_memory[fd], '\n'))
	{
		*line = ft_get_line(s_memory[fd]);
		aux = ft_strdup(ft_get_after_line(s_memory[fd]));
		free(s_memory[fd]);
		s_memory[fd] = ft_strdup(aux);
		free(aux);
		return (1);
	}
	*line = ft_strdup(s_memory[fd]);
	free(s_memory[fd]);
	s_memory[fd] = 0;
	return (0);
}

static int	loop(int const fd, char **s_memory)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (-1);
		}
		if (!bytes_read)
			break ;
		buffer[bytes_read] = 0;
		ft_save_buffer(buffer, s_memory, fd);
		if (ft_strchr(s_memory[fd], '\n'))
			break ;
	}
	free(buffer);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*s_memory[4096];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!s_memory[fd])
		s_memory[fd] = ft_strdup("");
	else if (ft_strchr(s_memory[fd], '\n'))
		return (ft_line_result(s_memory, line, fd));
	if (loop(fd, s_memory))
		return (-1);
	return (ft_line_result(s_memory, line, fd));
}
