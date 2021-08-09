/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:56 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 12:36:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_hexa(t_map *map)
{
	int	r;
	int	g;
	int	b;

	r = map->ceiling.red;
	g = map->ceiling.green;
	b = map->ceiling.blue;
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_error(ERR_RGB, COLOR, map);
	map->ceiling.hexa = (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
	r = map->floor.red;
	g = map->floor.green;
	b = map->floor.blue;
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_error(ERR_RGB, COLOR, map);
	map->floor.hexa = (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	note_color(int ref, char pos, int color, t_map *map)
{
	if (pos == 'C')
	{
		if (ref == 0)
			map->ceiling.red = color;
		if (ref == 1)
			map->ceiling.green = color;
		if (ref == 2)
			map->ceiling.blue = color;
	}
	else if (pos == 'F')
	{
		if (ref == 0)
			map->floor.red = color;
		if (ref == 1)
			map->floor.green = color;
		if (ref == 2)
			map->floor.blue = color;
	}
}

int	get_color(char *line, t_map *map)
{
	int	i;
	int	debut;
	int	which_col;
	int	color;

	which_col = 0;
	map->param++;
	i = 0;
	while (i < ft_len(line))
	{
		debut = i + 1;
		i++;
		while ((which_col < 2 && line[i] != ',')
			|| (which_col == 2 && line[i] != '\0'))
			i++;
		color = ft_atoi_new(line, debut, i);
		note_color(which_col, line[0], color, map);
		which_col++;
		if (which_col == 3)
		{
			ft_hexa(map);
			return (1);
		}
	}
	ft_error(ERR_COLOR, COLOR, map);
}
