#ifndef FILLER_H
# define FILLER_H
# define FD 0
# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_data
{
	char		**grid_map;
	int			**heat_map;
	char		**grid_token;
	char 		*line;
	char		me;
	char		enemy;
	int			width_map;
	int			height_map;
	int			width_token;
	int			height_token;
}				t_data;

typedef struct	s_cell
{
	int			x;
	int			y;
	int			score;
}				t_cell;

void			error(t_data *data, char *line);
void			get_info_about_game(t_data *data);
void			get_maps(t_data *data, int y);
void			make_heat_map(t_data *data);
int				get_absolute_value(int a, int b);
void			is_num(t_data *data, char *checked);
void			parse_size(t_data *data, char *check_line, int size);
void			fill_heat_map(int **map, int height, int width);
void			free_data(t_data *data);

#endif
