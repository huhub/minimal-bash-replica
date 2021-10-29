#include "../../src/utils/utils.h"
#include <assert.h>

static void	mix(void)
{
	char	**result;

	result = 0;
	result = ft_splitter("comando1 arg1 \"| comando2 arg1'| co'mando3\" hey",
		'|');
	assert(result && "comando1 arg1 \"| comando2 arg1'| co'mando3\" hey");
	assert(!ft_strcmp(result[0],
		"comando1 arg1 \"| comando2 arg1'| co'mando3\" hey")
		&& "comando1 arg1 \"| comando2 arg1'| co'mando3\" hey");
	free_2dim_str(result);
	result = ft_splitter("comando1 arg1 \"| comando2 arg1'\"| co'mando3' hey",
		'|');
	assert(result && "comando1 arg1 \"| comando2 arg1'\"| co'mando3' hey");
	assert(!ft_strcmp(result[0],
		"comando1 arg1 \"| comando2 arg1'\"")
		&& "comando1 arg1 \"| comando2 arg1'| co'mando3\" hey");
	assert(!ft_strcmp(result[1],
		" co'mando3' hey")
		&& "comando1 arg1 \"| comando2 arg1'| co'mando3\" hey");
	free_2dim_str(result);
}

static void	single_quotes(void)
{
	char	**result;

	result = 0;
	result = ft_splitter("comando1 arg1 '| comando2' arg1", '|');
	assert(result && "comando1 arg1 '| comando2' arg1");
	assert(!ft_strcmp(result[0], "comando1 arg1 '| comando2' arg1")
		&& "comando1 arg1 '| comando2' arg1");
	assert(!result[1] && "comando1 arg1 '| comando2' arg1");
	free_2dim_str(result);
}

static void	double_quotes(void)
{
	char	**result;

	result = 0;
	result = ft_splitter("comando1 arg1 \"| comando2\" arg1", '|');
	assert(result && "comando1 arg1 \"| comando2\" arg1");
	assert(!ft_strcmp(result[0], "comando1 arg1 \"| comando2\" arg1")
		&& "comando1 arg1 \"| comando2\" arg1");
	assert(!result[1] && "comando1 arg1 \"| comando2\" arg1");
	free_2dim_str(result);
}

static void	no_quotes(void)
{
	char	**result;

	result = 0;
	result = ft_splitter("comando1 arg1 | comando2 arg1", '|');
	assert(result && "comando1 arg1 | comando2 arg1");
	assert(!ft_strcmp(result[0], "comando1 arg1 ")
		&& "comando1 arg1 | comando2 arg1");
	assert(!ft_strcmp(result[1], " comando2 arg1")
		&& "comando1 arg1 | comando2 arg1");
	assert(!result[2] && "comando1 arg1 | comando2 arg1");
	free_2dim_str(result);
}

int	main(void)
{
	no_quotes();
	double_quotes();
	single_quotes();
	mix();
	return (0);
}