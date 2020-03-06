#include "../include/filler.h"

static void		init_data(t_data *data)
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

int				find_place(t_cell *cell, t_data *data, char enemy,
											int covered_piece)
{
	int		y;
	int		x;

	y = -1;
	while (++y < data->height_token)
	{
		x = -1;
		while (++x < data->width_token)
		{
			if (data->grid_token[y][x] == '*')
			{
				if ((cell->y + y) < 0 || (cell->y + y) >= data->height_map
				|| (cell->x + x) < 0 || (cell->x + x) >= data->width_map ||
					data->grid_map[cell->y + y][cell->x + x] == data->enemy
					|| data->grid_map[cell->y + y][cell->x + x] == enemy)
					return (0);
				cell->score += data->heat_map[cell->y + y][cell->x + x];
				if (data->grid_map[cell->y + y][cell->x + x] == data->me)
					covered_piece++;
				if (covered_piece > 1)
					return (0);
			}
		}
	}
	return ((covered_piece == 1) ? 1 : 0);
}

void			put_token(t_data *data)
{
	t_cell	checked;
	t_cell	chosen;
	char	enemy;

	chosen.y = 0;
	chosen.x = 0;
	chosen.score = 2147483647;
	enemy = (data->enemy == 'O') ? 'o' : 'x';
	checked.y = -(data->height_token) - 1; //чекнуть границы может и без этого норм работать будет ?
	while (++checked.y < data->height_map + data->height_token)
	{
		checked.x = -(data->width_token) - 1;
		while (++checked.x < data->width_map + data->width_token) //убрал равно
		{
			checked.score = 0;
			if (find_place(&checked, data, enemy, 0) && checked.score < chosen.score)
			{
				chosen.score = checked.score;
				chosen.x = checked.x;
				chosen.y = checked.y;
			}
		}
	}
	ft_printf("%i %i\n", chosen.y, chosen.x);
}

static void		get_token(t_data *data)
{
	int		x;
	int 	y;

	parse_size(data, "Piece ", 6);
	if (!(data->grid_token = (char**)malloc(sizeof(char *)
			* (data->height_token + 1))))
		error(data, "Error: unable to allocate memory\n");
	data->grid_token[data->height_token] = NULL;
	y = -1;
	while (++y < data->height_token)
	{
		if (get_next_line(FD, data->grid_token + y) < 0)
			error(data, "Error: invalid token\n");
		x = -1;
		while (data->grid_token[y][++x] != '\0')
			if (data->grid_token[y][x] != '*' && data->grid_token[y][x] != '.')
				error(data, "Error: invalid token\n");
	}
}

int				main(void)
{
	t_data data;

	init_data(&data);
	get_info_about_game(&data);
	while (1)
	{
		parse_size(&data, "Plateau ", 8);
		get_maps(&data, 0);
		get_token(&data);
		make_heat_map(&data);
		put_token(&data);
		free_data(&data);
	}
	return (0);
}
