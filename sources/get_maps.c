#include "../include/filler.h"

void			get_info_about_game(t_data *data)
{
	if (get_next_line(FD, &(data->line)) <= 0)
		error(data, "Error: unable to get info from stdin\n");
	if (data->line[10] != '1' && data->line[10] != '2')
		error(data, "Error: invalid info about player\n");
	data->me = (data->line[10] == '1') ? 'O' : 'X';
	data->enemy = (data->line[10] == '1') ? 'X' : 'O';
	free(data->line);
	data->line = NULL;
}

char			*get_line(t_data *data)
{
	char 	*line;

	if (!(line = ft_strchr(data->line, ' ') + 1))
		error(data, "Error: invalidate map\n");
	/*while(*line != '\0')
	{
		if (*line != '.' && *line != 'O' && *line != 'o'
			&& *line != 'X' && *line != 'x')
			error(data, "Error: invalidate map\n");
		line++;
	}
	line = ft_strchr(data->line, ' ') + 1;*/
	if (!(line = ft_strdup(line)))
		error(data, "unable to allocate memory\n");
	return (line);
}

void			get_maps(t_data *data)
{
	int 	y;

	if(!(data->grid_map = (char**)malloc(sizeof(char *) * (data->height_map + 1))))
		error(data, "Error: unable to allocate memory\n");
	data->grid_map[data->height_map] = NULL;
	if (!(data->heat_map = (int**)malloc(sizeof(int*) * (data->height_map + 1))))
		error(data, "Error: unable to allocate memory\n");
	data->heat_map[data->height_map] = NULL;
	if (get_next_line(FD, &(data->line)) <= 0)
		error(data, "Error: unable to get info from stdin\n");
	free(data->line);
	data->line = NULL;
	y = -1;
	while (++y < data->height_map)
	{
		if (get_next_line(FD, &(data->line)) <= 0)
			return (error(data, "Error: unable to get info from stdin\n"));
		data->grid_map[y] = get_line(data);
		free(data->line);
		data->line = NULL;
		if (!(data->heat_map[y] = (int*)malloc(sizeof(int) * data->width_map)))
			error(data, "Error: unable to allocate memory\n");
	}
	fill_heat_map(data->heat_map, data->height_map, data->width_map);
}

static void		get_distance(int x_enemy, int y_enemy, t_data *data)
{
	int		x;
	int		y;
	int		dist;
	int 	height;
	int 	width;

	y = -1;
	height = data->height_map;
	width = data->width_map;
	while (++y < height)
	{
		x = -1;
		while (++x < width) //как считать в зависимости от последнего поставленного х ?
		{
			if (data->grid_map[y][x] != 'o' && data->grid_map[y][x] != 'O' &&
				data->grid_map[y][x] != 'x' && data->grid_map[y][x] != 'X')
			{
				dist = get_absolute_value(x, x_enemy) + get_absolute_value(y, y_enemy);
				if (data->grid_map[y][x] == '.' ||
						(dist != -1 && dist < data->heat_map[y][x]))
					data->heat_map[y][x] = dist;
			}
		}
	}
}

void			make_heat_map(t_data *data)
{
	int 	y;
	int 	x;
	char 	enemy;

	y = -1;
	while (++y < data->height_map)
	{
		x = -1;
		while (++x < data->width_map)
			data->heat_map[y][x] = -1;
	}
	y = -1;
	enemy = (data->enemy == 'O') ? 'o' : 'x';
	while (++y < data->height_map)
	{
		x = -1;
		while (++x < data->width_map)
		{
			if (data->grid_map[y][x] == enemy || data->grid_map[y][x] == data->enemy)
			{
				data->heat_map[y][x] = -1;
				get_distance(x, y, data);
			}
		}
	}
}