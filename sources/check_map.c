/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:02:20 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 16:19:14 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	put_texture(char *line, t_map *map, char *copy)
{
	if (line[0] == 'N')
		map->no.path = copy;
	if (line[0] == 'E')
		map->ea.path = copy;
	if (line[0] == 'S')
		map->so.path = copy;
	if (line[0] == 'W')
		map->we.path = copy;
}

int	get_text_len(char *line, t_map *map)
{
	int	i;
	int	cpt;

	i = 3;
	cpt = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0' && line[i] != ' ')
	{
		i++;
		cpt++;
	}
	if (line[i] != '\0')
	{
		while (i != ft_len(line))
		{
			if (line[i] != '\0' && line[i] != ' ')
				ft_error(ERR_PATH, PATH, map);
			i++;
		}
	}
	return (cpt);
}

int	get_texture(char *line, t_map *map)
{
	int		i;
	int		j;
	int		len;
	char	*copy;

	i = 3;
	while (line[i] == ' ')
		i++;
	len = get_text_len(line, map);
	copy = malloc(sizeof(char) * len + 1);
	if (!copy || (len == 0))
		ft_error(ERR_PATH, PATH, map);
	j = i;
	while (i < j + len)
	{
		copy[i - j] = line[i];
		i++;
	}
	copy[len] = '\0';
	put_texture(line, map, copy);
	copy = NULL;
	free (copy);
	map->param++;
	return (1);
}

int	get_resolution(char *line, t_map *map)
{
	int	i;
	int	debut;

	i = 2;
	while (line[i] == ' ')
		i++;
	debut = i;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] == ' ')
		map->rx = ft_atoi_new(line, debut, i);
	else
		ft_error(ERR_CHAR, CHAR, map);
	while (line[i] == ' ')
		i++;
	debut = i;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (i != debut && (line[i] == ' ' || line[i] == '\0'))
		map->ry = ft_atoi_new(line, debut, i);
	else
		ft_error(ERR_CHAR, CHAR, map);
	check_end_line(line, i);
	map->param++;
	return (1);
}

int	isparam(char *line, t_map *map)
{
	if ((line[0] == 'C' || line[0] == 'F') && (line[1] == ' '))
		return (get_color(line, map));
	if ((line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		|| (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		|| (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		|| (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		|| (line[0] == 'S' && line[1] == ' '))
		return (get_texture(line, map));
	else if ((line[0] == 'R') && (line[1] == ' '))
		return (get_resolution(line, map));
	else
		ft_error(ERR_ELEM, ELEM, map);
}
