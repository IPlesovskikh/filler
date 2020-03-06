#include "../include/filler.h"

int			find_place(t_cell *cell, t_data *data, char enemy)
{
	int		y;
	int		x;
	int		covered_piece;

	covered_piece = 0;
	y = -1;
	while (++y < data->height_token)
	{
		x = -1;
		while (++x < data->width_token)
		{
			if (data->grid_token[y][x] == '*')
			{
				if (data->grid_map[cell->y + y][cell->x + x] == data->enemy
					|| data->grid_map[cell->y + y][cell->x + x] == enemy)
					return (0);
				cell->score += data->heat_map[cell->y + y][cell->x + x];
				if (data->grid_map[cell->y + y][cell->x + x] == data->me) //me же не может быть маленькой ?
					covered_piece++;
				if (covered_piece > 1)
					return (0);
			}
		}
	}
	return ((covered_piece == 1) ? 1 : 0);
}

void		put_token(t_data *data)
{
	t_cell	checked;
	t_cell	chosen;
	char 	enemy;

	chosen.y = 0;
	chosen.x = 0;
	chosen.score = 2147483647;
	enemy = (data->enemy == 'O') ? 'o' : 'x';
	checked.y = -1;
	while (++checked.y + data->height_token - 1 < data->height_map)
	{
		checked.x = -1;
		while (++checked.x + data->width_token - 1 < data->width_map) //убрал равно
		{
			checked.score = 0;
			if (find_place(&checked, data, enemy) && checked.score < chosen.score)
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
	if (!(data->grid_token = (char**)malloc(sizeof(char *) * (data->height_token + 1)))) //занулить иначе мусор попадается memalloc
		error(data, "Error: unable to allocate memory\n");
	data->grid_token[data->height_token] = NULL;
	y = 0;
	while (y < data->height_token)
	{
		if (get_next_line(FD, data->grid_token + y) < 0) //чекнуть на валидность линии
			error(data, "Error: invalid token\n");
		x = -1;
		/*
		while (data->grid_token[y][++x] != '\0')
			if (data->grid_token[y][x] != '*' && data->grid_token[y][x] != '.')
				error(data, "Error: invalid token\n");
				*/
		y++;
	}
}

int				main(void)
{
	t_data data;

	init_data(&data);
	get_info_about_game(&data);
	while(1)
	{
		parse_size(&data, "Plateau ", 8);
		get_maps(&data);
		get_token(&data);
		make_heat_map(&data);
		put_token(&data);
		free_data(&data);
	}
	return (0);
}