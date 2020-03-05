#include "filler.h"

int			find_place(t_cell *cell, t_data *data)
{
	int		y;
	int		x;
	int		covered_piece;

	cell->score = 0;
	covered_piece = 0;
	y = -1;
	while (++y < data->height_token)
	{
		x = -1;
		while (++x < data->width_token)
		{
			if (data->grid_token[y][x] == '*')
			{
				if (data->grid_map[cell->y + y][cell->x + x] == data->enemy) // О или о или тут учитывается последний ?
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

	chosen.y = 0;
	chosen.x = 0;
	chosen.score = 2147483647; //посмотреть где еще встречается чек на это число
	checked.y = -1;
	while (++checked.y <= data->height_map)
	{
		checked.x = -1;
		while (++checked.x <= data->width_map)
		{
			if (find_place(&checked, data) && checked.score < chosen.score)
			{
				chosen.score = checked.score;
				chosen.x = checked.x;
				chosen.y = checked.y;
			}
		}
	}
	ft_printf("%d %d\n", chosen.y, chosen.x);
}

static void		get_token(t_data *data)
{
	int		i;

	parse_size(data, "Piece ", 7);
	if (!(data->grid_token = (char**)malloc(sizeof(char *) * (data->height_token))))
		error(data, "Error: unable to allocate memory\n");
	i = 0;
	while (i < data->height_map)
		if (get_next_line(FD, data->grid_token + i++) < 0) //чекнуть на валидность линии
			error(data, "Error: invalid token\n");
}
//посмотреть что за ошибка в специальный поток ? wstygg
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
	}
	return (0);
}