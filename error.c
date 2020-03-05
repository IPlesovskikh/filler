#include "filler.h"

static void	free_array(char ***array)
{
	int 	i;

	i = -1;
	while((*array)[++i] != NULL)
		free((*array)[i]);
	free(*array);
	(*array) = NULL;
}

static void	free_array_int(int ***array)
{
	int 	i;

	i = -1;
	while((*array)[++i] != NULL)
		free((*array)[i]);
	free(*array);
	(*array) = NULL;
}

void		error(t_data *data, char *line)
{
	if (data->line)
		free(data->line);
	if (data->grid_token)
		free_array(&(data->grid_token));
	if (data->grid_map)
		free_array(&(data->grid_map));
	if (data->heat_map)
		free_array_int(&(data->heat_map));
	ft_printf("%s", line);
	exit(1);
}
