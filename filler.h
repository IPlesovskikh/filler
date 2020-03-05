#ifndef FILLER_H
# define FILLER_H
# define MAX_VALUE 2147483647
# define FD 0
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct	s_data
{
	char 		*line;
	int			player; // это нужно ?
	char		me;
	char		enemy;
	int			width_map;
	int			height_map;
	char		**grid_map;
	int			**heat_map;
	int			width_token;
	int			height_token;
	char		**grid_token;
	int			width_r;
	int			height_r;
	int			x_offset;
	int			y_offset;
}				t_data;

typedef struct	s_cell
{
	int			x;
	int			y;
	int			score;
}				t_cell;

void			error(t_data *data, char *line);
void			get_info_about_game(t_data *data);
void			get_maps(t_data *data);
void			make_heat_map(t_data *data);

#endif
