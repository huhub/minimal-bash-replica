#include "utils.h"

void	custom_err_msg(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}
