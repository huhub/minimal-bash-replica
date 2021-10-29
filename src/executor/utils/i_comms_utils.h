#ifndef I_COMMS_UTILS_H
# define I_COMMS_UTILS_H

# include "../executor.h"

int	get_fd(int *fd, t_globvar *g_var);
int	check_valid_varname(char const *name);

#endif
