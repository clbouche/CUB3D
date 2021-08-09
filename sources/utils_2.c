/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:27 by user42            #+#    #+#             */
/*   Updated: 2021/07/13 17:34:53 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_len(char *ptr)
{
	int	a;

	a = 0;
	if (ptr == (char *)0)
		return (0);
	while (ptr[a])
		a++;
	return (a);
}

void	check_end_line(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ')
			ft_error_bis(ERR_CHAR, CHAR);
		i++;
	}
}

void	ft_bzero(t_map *map)
{
	map->fd = 0;
	map->rx = 0;
	map->ry = 0;
	map->debut = 0;
	map->fin = 0;
	map->param = 0;
	map->nblines = 0;
	map->max = 0;
	map->floor.blue = 0;
	map->floor.red = 0;
	map->floor.green = 0;
	map->ceiling.blue = 0;
	map->ceiling.green = 0;
	map->ceiling.red = 0;
	map->screenx = 0;
	map->screeny = 0;
	map->wall = 0;
	map->end_reached = 0;
	map->realmap = NULL;
}
