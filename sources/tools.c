#include "../include/filler.h"

void		is_num(t_data *data, char *checked)
{
	int 	i;

	i = -1;
	while (checked[++i] != ' ' && checked[i] != '\0' && checked[i] != ':')
		if (checked[i] < '0' || '9' < checked[i])
			error(data, "Error: invalid info about size\n");
}

int			get_absolute_value(int a, int b)
{
	int res;

	res = a - b;
	res = (res > 0) ? res : -res;
	return (res);
}

void		parse_size(t_data *data, char *check_line, int size)
{
	char	*height;
	char	*width;

	if (get_next_line(FD, &(data->line)) <= 0)
		error(data, "Error: unable to get info from stdin\n");
	if (!ft_strnequ(data->line, check_line, size))
		error(data, "Error: invalid info about size\n");
	if (!(height = ft_strchr(data->line, ' ') + 1))
		error(data, "Error: invalid info about size\n");
	is_num(data, height);
	if (!(width = ft_strchr(height, ' ') + 1))
		error(data, "Error: invalid info about size\n");
	is_num(data, width);
	if (size == 8)
	{
		data->height_map = ft_atoi(height);
		data->width_map = ft_atoi(width); //проверить число на переполнение или нет ? отдельная функция в instruments
	}
	else
	{
		data->height_token = ft_atoi(height);
		data->width_token = ft_atoi(width);
	}
	free(data->line);
	data->line = NULL;
}

void		init_data(t_data *data)
{
	data->height_map = 0;
	data->width_map = 0;
	data->grid_map = NULL;
	data->heat_map = NULL;
	data->grid_token = NULL;
	data->width_token = 0;
	data->height_map = 0;
	data->enemy = 0;
	data->me = 0;
	data->line = NULL;
}


void		fill_heat_map(int **map, int height, int width)
{
	int		x;
	int		y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			map[y][x] = 0;
	}
}



