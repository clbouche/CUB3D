/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:41 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 10:01:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_rotate_left(t_map *map)
{
	double	old_x;
	double	old_y;
	double	alpha;

	alpha = - (acos (-1) / 6);
	old_x = map->pos.dirx;
	old_y = map->pos.diry;
	map->pos.dirx = cos(alpha) * old_x - sin(alpha) * old_y;
	map->pos.diry = sin(alpha) * old_x + cos(alpha) * old_y;
	old_x = map->pos.planx;
	old_y = map->pos.plany;
	map->pos.planx = cos(alpha) * old_x - sin(alpha) * old_y;
	map->pos.plany = sin(alpha) * old_x + cos(alpha) * old_y;
}

void	ft_rotate_right(t_map *map)
{
	double	old_x;
	double	old_y;
	double	alpha;

	alpha = (acos(-1) / 6);
	old_x = map->pos.dirx;
	old_y = map->pos.diry;
	map->pos.dirx = cos(alpha) * old_x - sin(alpha) * old_y;
	map->pos.diry = sin(alpha) * old_x + cos(alpha) * old_y;
	old_x = map->pos.planx;
	old_y = map->pos.plany;
	map->pos.planx = cos(alpha) * old_x - sin(alpha) * old_y;
	map->pos.plany = sin(alpha) * old_x + cos(alpha) * old_y;
}
