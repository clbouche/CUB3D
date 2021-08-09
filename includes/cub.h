/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:49:24 by cnahmias          #+#    #+#             */
/*   Updated: 2021/07/12 17:21:23 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "errors.h"
# include "get_next_line.h"

# define MOVE_TO_LEFT_A 97
# define FORWARD_W 119
# define MOVE_TO_RIGHT_D 100
# define BACK_S 115
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define ESC 65307

typedef struct s_pos
{
	int		found;
	double	posx;
	double	posy;
	char	dir;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	raydirx;
	double	raydiry;
	double	cam;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		side;
	double	dist;
	double	rh;
	int		drawstart;
	int		drawend;
	int		x;
}			t_pos;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_vars;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	hexa;
}				t_color;

typedef struct s_text
{
	char	*path;
	int		width;
	int		height;
	int		len;
	int		bpp;
	int		size;
	int		endian;
	void	*img;
	int		*data;
	char	*addr;
}				t_text;

typedef struct s_map
{
	int		fd;
	int		debut;
	int		param;
	int		nblines;
	int		max;
	t_color	ceiling;
	t_color	floor;
	t_text	no;
	t_text	so;
	t_text	ea;
	t_text	we;
	int		fin;
	char	**realmap;
	t_pos	pos;
	t_vars	img;
	int		rx;
	int		ry;
	int		screenx;
	int		screeny;
	double	wall;
	int		end_reached;
}			t_map;

void	ft_px_put(t_vars *var, int x, int y, int color);
void	draw_line(t_map *map, int x1, int y1, int y2);
int		ft_isdigit(int c, int i, int fin);
char	*ft_strcopy2(char *s, t_map *map);
int		ft_isspace(int c, int i, int fin);
int		ft_atoi_new(const char *str, int debut, int fin);
void	note_color(int ref, char pos, int color, t_map *map);
int		get_color(char *line, t_map *map);
int		get_texture(char *line, t_map *map);
int		get_texy(t_map *map, double texpos);
long	*get_img_addr(t_map *map, int texx, int texy);
int		get_texx(t_map *map, double wall);
double	get_step(t_map *map, int start, int end);
int		get_resolution(char *line, t_map *map);
int		isparam(char *line, t_map *map);
void	check_line(char *line, t_map *map, int nb);
void	check_cub(char *string);
int		parse_cub(char **argv, t_map *map);
int		ft_len(char *ptr);
void	fill_map(char **argv, t_map *map);
int		neighbors(char **realmap, int row, int col);
int		check_car(char c, int row, int col, t_map *map);
int		check(char **realmap, int nblines, t_map *map);
void	ft_posplayer(t_map *map, int size);
void	trace_col(t_map *map, int x);
void	ft_checkhit(t_map *map, int x);
void	ft_stepside(t_map *map, int x);
void	ft_rotate_left(t_map *map);
void	ft_rotate_right(t_map *map);
void	ft_go_forward(t_map *map, double speed);
void	ft_go_back(t_map *map, double speed);
void	ft_go_left(t_map *map, double speed);
void	ft_go_right(t_map *map, double speed);
int		deal_key(int key, t_map *map);
int		deal_mouse(int key, t_map *map);
int		ft_raycast(t_map *map);
void	ft_texture(t_map *map);
void	draw_texture_loop(double texpos, t_map *map, int x, int y);
void	draw_texture(t_map *map, int x, int start, int end);
void	ft_putstr(char *str);
void	ft_error(char *error, char *usage, t_map *map);
void	ft_error_bis(char *error, char *usage);
void	ft_bzero(t_map *map);
void	free_realmap(t_map *map);
void	check_end_line(char *line, int i);

#endif
