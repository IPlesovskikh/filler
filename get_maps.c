#include "filler.h"

void			get_info_about_game(t_data *data)
{
	char	*temp;

	if (get_next_line(FD, &(data->line)) <= 0)
		return (error(data, "Error: unable to get info from stdin\n"));
	if (data->line[10] != '1' && data->line[10] != '2')
		return (error(data, "Error: invalid info about player\n"));
	data->me = (data->line[10] == '1') ? 'O' : 'X';
	data->enemy = (data->line[10]) == '1' ? 'X' : 'O';
	free(&(data->line));
	data->line = NULL;
	if (get_next_line(FD, &(data->line)) <= 0)
		return (error(data, "Error: unable to get info from stdin\n"));;
	if (!ft_strnequ(data->line, "Plateau", 7))
		return (error(data, "Error: invalid map\n"));
	data->height_map = ft_atoi(data->line[8]);
	temp = ft_strchr(data->line, ' ') + 1;
	temp = ft_strchr(temp, ' ') + 1;
	data->width_map = ft_atoi(temp);
	free(data->line);
	data->line = NULL;
}

void			get_maps(t_data *data)
{
	int 	y;

	if(!(data->grid_map = (char**)malloc(sizeof(char *) * (data->height_map))))
		error(data, "Error: unable to allocate memory\n");
	if (!(data->heat_map = (int**)malloc(sizeof(int*) * data->height_map)))
		error(data, "Error: unable to allocate memory\n");
	if (get_next_line(FD, &(data->line)) <= 0)
		return (error(data, "Error: unable to get info from stdin\n"));
	free(data->line);
	data->line = NULL;
	y = -1;
	while (++y < data->height_map)
	{
		if (get_next_line(FD, &(data->line)) <= 0)
			return (error(data, "Error: unable to get info from stdin\n"));
		data->grid_map[y] = ft_strdup(ft_strchr(data->line, ' ') + 1);
		free(data->line);
		data->line = NULL;
		if (!(data->heat_map[y] = (int*)malloc(sizeof(int) * data->width_map)))
			error(data, "Error: unable to allocate memory\n");
	}
}


static int		get_modul(int a, int b)
{
	int res;

	res = a - b;
	res = (res > 0) ? res : -res;
	return (res);
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
		while (++x < width) //считать в зависимости от последнего поставленного х ?
		{
			if (data->grid_map[x][y] != 'o' && data->grid_map[x][y] != 'O' &&
				data->grid_map[x][y] != 'x' && data->grid_map[x][y] != 'X')
			{
				dist = get_modul(x, x_enemy) + get_modul(y, y_enemy);
				if (data->grid_map[x][y] == '.' ||
						(dist != -1 && dist < data->heat_map[x][y]))
					data->heat_map[x][y] = dist;
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
			data->heat_map[x][y] = -1;
	}
	y = -1;
	enemy = (data->enemy == 'O') ? 'o' : 'x';
	while (++y < data->height_map)
	{
		x = -1;
		while (++x < data->width_map)
		{
			if (data->grid_map[x][y] == enemy || data->grid_map[x][y] == data->enemy)
			{
				data->heat_map[x][y] = -2;
				get_distance(x, y, data);
			}
		}
	}
}