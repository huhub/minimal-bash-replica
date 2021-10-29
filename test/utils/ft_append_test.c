#include "../../src/utils/utils.h"
#include <assert.h>

void	empty(void)
{
	char	*dst;
	int		result;

	dst = 0;
	result = 0;
	result = ft_append(&dst, "hola, como estas?");
	assert(!result && "hola, como estas?");
	assert(!ft_strcmp(dst, "hola, como estas?") && "hola, como estas?");
	free(dst);
	dst = ft_strdup("hola");
	result = ft_append(&dst, 0);
	assert(result && "NULL");
	assert(!ft_strcmp(dst, "hola") && "NULL");
	result = ft_append(&dst, "");
	assert(!result && "\"\"");
	assert(!ft_strcmp(dst, "hola") && "\"\"");
	free(dst);
	dst = 0;
	result = ft_append(&dst, 0);
	assert(result && "NULL");
	assert(!dst && "NULL");
}

void	non_empty(void)
{
	char	*dst;
	int		result;

	dst = ft_strdup("hola");
	result = 0;
	result = ft_append(&dst, ", que tal?");
	assert(!result && ", que tal?");
	assert(!ft_strcmp(dst, "hola, que tal?") && ", que tal?");
	free(dst);
}

void	long_src(void)
{
	char	*dst;
	int		result;

	dst = ft_strdup("hola");
	result = 0;
	result = ft_append(&dst,
	"diosholadiosholadiosholadiosholadiosholadiosholadiosholadiosholadios");
	assert(!result
	&& "diosholadiosholadiosholadiosholadiosholadiosholadiosholadiosholadios");
	assert(!ft_strcmp(dst,
	"holadiosholadiosholadiosholadiosholadiosholadiosholadiosholadiosholadios")
	&& "diosholadiosholadiosholadiosholadiosholadiosholadiosholadiosholadios");
	free(dst);
}

void	long_dst(void)
{
	char	*dst;
	int		result;

	dst = ft_strdup("holadiosholadiosholadiosholadiosholadiosholadiosholadios");
	result = 0;
	result = ft_append(&dst,
	"hola");
	assert(!result
	&& "hola");
	assert(!ft_strcmp(dst,
	"holadiosholadiosholadiosholadiosholadiosholadiosholadioshola")
	&& "hola");
	free(dst);
}

int	main(void)
{
	empty();
	non_empty();
	long_src();
	long_dst();
	return (0);
}