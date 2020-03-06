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
	char	*line;

	if (!(line = ft_strchr(data->line, ' ')))
		error(data, "Error: invalidate map---1\n");
	line += 1;
	while(*line != '\0')
	{
		if (*line != '.' && *line != 'O' && *line != 'o'
			&& *line != 'X' && *line != 'x')
			error(data, "Error: invalidate map-----2\n");
		line++;
	}
	line = ft_strchr(data->line, ' ') + 1;
	if (!(line = ft_strdup(line)))
		error(data, "unable to allocate memory\n");
	return (line);
}

void			get_maps(t_data *data, int y)
{
	if (!(data->grid_map = (char**)ft_memalloc(sizeof(char *) *
			(data->height_map + 1))))
		error(data, "Error: unable to allocate memory\n");
	data->grid_map[data->height_map] = NULL;
	if (!(data->heat_map = (int**)ft_memalloc(sizeof(int*) *
			(data->height_map + 1))))
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
		if (!(data->heat_map[y] = (int*)ft_memalloc(sizeof(int) * data->width_map)))
			error(data, "Error: unable to allocate memory\n");
	}
	fill_heat_map(data->heat_map, data->height_map, data->width_map);
}

static int		get_distance(t_data *data, int x, int y)
{
	int		k;
	int		i;
	int		dist;
	int		min_dist;
	char	enemy;

	min_dist = 2147483647;
	enemy = (data->enemy == 'O') ? 'o' : 'x';
	k = -1;
	while (++k < data->height_map)
	{
		i = -1;
		while (++i < data->width_map)
		{
			if (data->grid_map[k][i] == data->enemy
					|| data->grid_map[k][i] == enemy)
			{
				dist = get_absolute_value(i, x) + get_absolute_value(k, y);
				if (dist < min_dist)
					min_dist = dist;
			}
		}
	}
	return (min_dist);
}

void			make_heat_map(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data->height_map)
	{
		x = -1;
		while (++x < data->width_map)
		{
			if (data->grid_map[y][x] == '.')
				data->heat_map[y][x] = get_distance(data, x, y);
		}
	}
}
