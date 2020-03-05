#include "filler.h"

static void		init_data(t_data *data)
{
	data->height_map = 0;
	data->width_map = 0;
	data->grid_map = NULL;
	data->heat_map = NULL;
	data->grid_token = NULL;
	data->width_token = 0;
	data->height_map = 0;
	data->player = 0;
	data->enemy = 0;
	data->me = 0;
	data->line = NULL;
}



static void		get_token()
{

}

int				main(void)
{
	t_data data;

	init_data(&data);
	get_info_about_game(&data);
	while(1)
	{
		get_maps(&data);
		get_token
		make_heat_map(&data);
	}
	return (0);
}