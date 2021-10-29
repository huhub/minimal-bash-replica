#include "../../src/interpreter/interpreter.h"
#include <assert.h>

static void	single_quotes(void)
{
	int		result;
	char	*dst;

	result = 0;
	dst = 0;
	result = space_remover("echo '' hola'que   tal' estas 'yo bien'y    tu''que'tal'estas.  ", &dst);
	assert(!result && "echo '' hola'que   tal' estas 'yo bien'y    tu''que'tal'estas.  ");
	assert(!ft_strcmp(dst, "echo  holaque   tal estas yo bieny tuquetalestas."));
	free(dst);
}

int	main(void)
{
	single_quotes();
	return (0);
}
