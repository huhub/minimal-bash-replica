#ifndef INTERNAL_COMMS_H
# define INTERNAL_COMMS_H

# include "../../utils/utils.h"
# include "../utils/i_comms_utils.h"

int		echo(char **args, t_globvar *g_var);
int		pwd(char **args, t_globvar *g_var);
int		cd(char **args, t_globvar *g_var);
int		env(char **args, t_globvar *g_var);
int		ft_exit(char **args, t_globvar *g_var);
int		export(char **args, t_globvar *g_var);
char	**split_var(char const *assignment);
int		check_valid_name(char const *name);
int		unset(char **args, t_globvar *g_var);

#endif
