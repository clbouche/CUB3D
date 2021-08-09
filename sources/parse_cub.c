/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:07:48 by clbouche          #+#    #+#             */
/*   Updated: 2021/07/12 17:33:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	delete_line(t_map *map, char *line)
{
	int	i;

	i = ft_len(line);
	free(line);
	if (map->debut == 0 && map->param < 7)
		ft_error(ERR_SCENE, SCENE, map);
	else if (map->debut != 0 && i == 0)
		map->end_reached = 1;
	else if (i != 0 && map->debut != 0)
	{
		if (map->end_reached == 1)
			ft_error(ERR, X, map);
	}
}

void	check_line(char *line, t_map *map, int nb)
{
	if (map->debut == 0 && map->param < 7)
	{
		if (ft_len(line) == 0 || isparam(line, map) == 1)
			free(line);
		else
			delete_line(map, line);
	}
	else if (map->debut != 0 && map->param == 7 && ft_len(line) != 0)
	{
		if (ft_len(line) > map->max)
			map->max = ft_len(line);
		map->nblines++;
		delete_line(map, line);
	}
	else if (map->debut == 0 && map->param == 7 && ft_len(line) != 0)
	{
		if (ft_len(line) > map->max)
			map->max = ft_len(line);
		map->debut = nb;
		map->nblines++;
		free(line);
	}
	else if (ft_len(line) == 0)
		delete_line(map, line);
}

void	check_cub(char *string)
{
	int	i;

	i = ft_len(string);
	if (string[i - 1] != 'b' || string[i - 2] != 'u'
		|| string[i - 3] != 'c' || string[i - 4] != '.'
		|| string[i] != '\0')
		ft_error_bis(ERR_NAME, NAME_ARG);
	i = i - 4;
	while (i > 0)
	{
		if (string[i] == ' ')
			ft_error_bis(ERR_NAME, NAME_ARG);
		i--;
	}
}

int	parse_cub(char **argv, t_map *map)
{
	char	*line;
	int		i;

	i = -1;
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		ft_error(ERR_PATH, FILE, map);
	while (get_next_line(map->fd, &line) == 1)
	{
		i++;
		check_line(line, map, i);
	}
	check_line(line, map, i);
	close(map->fd);
	map->fin = map->debut + map->nblines;
	fill_map(argv, map);
	return (check(map->realmap, map->nblines, map));
}
