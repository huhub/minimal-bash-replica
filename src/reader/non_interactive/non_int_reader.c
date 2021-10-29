#include "non_int_reader.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_final_path(char **final_path, char const *filename, t_globvar *g_var)
{
	char	*path;

	if (!check_path(filename))
	{
		if (get_directory_entry(get_value("PWD", g_var->envp), filename))
			*final_path = ft_strdup(filename);
		else
		{
			path = get_path(filename, g_var);
			if (!path)
				return (1);
			ft_append(final_path, path);
			ft_append(final_path, "/");
			if (ft_append(final_path, filename))
				return (1);
		}
	}
	else
		*final_path = ft_strdup(filename);
	return (0);
}

static int	get_script_fd(char *filename, t_globvar *g_var)
{
	int		fd;
	char	*final_path;

	fd = -1;
	final_path = 0;
	if (get_final_path(&final_path, filename, g_var))
		return (-1);
	if (access(final_path, X_OK))
	{
		perror("access");
		free(final_path);
		return (fd);
	}
	fd = open(final_path, O_RDONLY);
	if (fd == -1)
		perror("open");
	free(final_path);
	return (fd);
}

static int	clean_exit(t_read_data *rdata, int const script_fd,
int const exit_code)
{
	if (rdata->input)
		free(rdata->input);
	if (rdata->first_input)
		free(rdata->first_input);
	close(script_fd);
	return (exit_code);
}

int	non_int_reader(char *filename, t_globvar *g_var)
{
	int			script_fd;
	t_read_data	rdata;
	int			read_res;

	script_fd = get_script_fd(filename, g_var);
	if (script_fd == -1)
		return (1);
	init_read_data(&rdata);
	while (1)
	{
		if (g_var->exit_command)
			return (clean_exit(&rdata, script_fd, 0));
		read_res = get_next_line(script_fd, &rdata.input);
		if (read_res == -1)
			return (clean_exit(&rdata, script_fd, 1));
		if (!read_res)
			return (clean_exit(&rdata, script_fd, 0));
		if (*rdata.input != '#')
		{
			if (process_input(&rdata, g_var))
				return (clean_exit(&rdata, script_fd, 1));
		}
		free(rdata.input);
		rdata.input = 0;
	}
}
