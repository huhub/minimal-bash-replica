#include "reader.h"

void	free_read_data(t_read_data *rdata)
{
	if (rdata->first_input)
		free(rdata->first_input);
	if (rdata->input)
		free(rdata->input);
	return ;
}

void	init_read_data(t_read_data *rdata)
{
	rdata->input = 0;
	rdata->first_input = 0;
}
