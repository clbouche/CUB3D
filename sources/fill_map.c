/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:00:49 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 17:05:50 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	fill_map(char **argv, t_map *map)
{
	int		i;
	int		j;
	int		fd;
	char	*line;	

	fd = open(argv[1], O_RDONLY);
	map->realmap = (char **)malloc(sizeof(char *) * (map->nblines));
	if (!(map->realmap))
		return ;
	i = 0;
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (i >= map->debut && i < map->fin)
		{	
			map->realmap[j] = ft_strcopy2(line, map);
			j++;
		}
		i++;
		free(line);
	}
	if (map->fin == i + 1)
		map->realmap[j] = ft_strcopy2(line, map);
	free(line);
	close(fd);
}

int	neighbors(char **realmap, int row, int col)
{
	if ((realmap[row][col + 1] == ' ') ||
		(realmap[row][col - 1] == ' ') ||
		(realmap[row + 1][col] == ' ') ||
		(realmap[row - 1][col] == ' '))
		ft_error_bis(ERR_MAP, MAP);
	return (1);
}

int	check_car(char c, int row, int col, t_map *map)
{
	if (c == '0')
		neighbors(map->realmap, row, col);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{	
		if (map->pos.found == 1)
			ft_error(ERR_PLAYER, PLAYER, map);
		map->pos.found = 1;
		neighbors(map->realmap, row, col);
	}
	return (0);
}

int	check_loop(char c, int row, int col, t_map *map)
{
	if (row == 0 || row == map->nblines - 1
		|| col == 0 || col == map->max - 1)
	{
		if (c != '1' && c != ' ')
			ft_error(ERR_MAP, MAP, map);
		return (++col);
	}
	else if (c == '0' || (c == 'N'
			|| c == 'E' || c == 'S' || c == 'W'))
	{
		check_car(c, row, col, map);
		return (++col);
	}
	else if (c == '1' || c == ' ')
		return (++col);
	else
		ft_error(ERR_MAP, MAP, map);
}

int	check(char **realmap, int nblines, t_map *map)
{
	int		col;
	int		row;
	char	c;

	row = 0;
	col = 0;
	map->pos.found = 0;
	while (row < nblines)
	{
		while (col < map->max)
		{
			c = realmap[row][col];
			col = check_loop(c, row, col, map);
		}
		row++;
		col = 0;
	}
	if (map->pos.found == 0)
		ft_error(ERR_PLAYER, PLAYER, map);
	return (0);
}
