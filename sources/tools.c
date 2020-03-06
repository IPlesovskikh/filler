#include "../include/filler.h"

void		is_num(t_data *data, char *checked)
{
	int		i;

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

int			get_number(char *number, t_data *data)
{
	int 	num;

	if ((num = ft_atoi(number)) == 0)
	{
		if (*number == '+' || *number == '-')
			number = number + 1;
		if (*number == '\0' || (*number != '0'
									 && *(number + 1) != ' ' && *(number + 1) != '\t'))
			error(data, "Error: invalid size's number\n");
	}
	return (num);
}

void		parse_size(t_data *data, char *check_line, int size)
{
	char	*height;
	char	*width;

	if (get_next_line(FD, &(data->line)) <= 0)
		error(data, "Error: unable to get info from stdin\n");
	if (!ft_strnequ(data->line, check_line, size))
		error(data, "Error: invalid info about size\n");
	if (!(height = ft_strchr(data->line, ' ')))
		error(data, "Error: invalid info about size\n");
	is_num(data, height + 1);
	if (!(width = ft_strchr(height + 1, ' ')))
		error(data, "Error: invalid info about size\n");
	is_num(data, width + 1);
	if (size == 8)
	{
		data->height_map = get_number(height + 1, data);
		data->height_map = get_number(width + 1, data);
	}
	else
	{
		data->height_token = get_number(height + 1, data);
		data->width_token = get_number(width + 1, data);
	}
	free(data->line);
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
