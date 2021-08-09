/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:02:02 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 17:05:27 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_error_bis(char *error, char *usage)
{
	printf("%s%s\n%s%s", ERR, error, USAGE, usage);
	exit(EXIT_FAILURE);
}

void	free_realmap(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nblines && map->realmap)
	{
		if (map->realmap[i])
			free(map->realmap[i]);
		i++;
	}
	if (map->realmap)
		free(map->realmap);
}

void	ft_error(char *error, char *usage, t_map *map)
{
	printf("%s%s\n%s%s", ERR, error, USAGE, usage);
	free_realmap(map);
	exit(EXIT_FAILURE);
}
