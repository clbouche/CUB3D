/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:50 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 10:01:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_go_forward(t_map *map, double speed)
{
	char	c;

	c = map->realmap[(int)(map->pos.posy
			+ (map->pos.diry * 2 * speed))][(int)map->pos.posx];
	if (c != '1')
		map->pos.posy += map->pos.diry * speed;
	c = map->realmap[(int)(map->pos.posy)][(int)(map->pos.posx
			+ (map->pos.dirx * 2 * speed))];
	if (c != '1')
		map->pos.posx += map->pos.dirx * speed;
}

void	ft_go_back(t_map *map, double speed)
{
	char	c;

	c = map->realmap[(int)(map->pos.posy
			- (map->pos.diry * 2 * speed))][(int)map->pos.posx];
	if (c != '1')
		map->pos.posy -= map->pos.diry * speed;
	c = map->realmap[(int)(map->pos.posy)]
	[(int)(map->pos.posx - (map->pos.dirx * 2 * speed))];
	if (c != '1')
		map->pos.posx -= map->pos.dirx * speed;
}

void	ft_go_right(t_map *map, double speed)
{
	char	c;

	c = map->realmap[(int)(map->pos.posy
			+ (map->pos.dirx * 2 * speed))][(int)map->pos.posx];
	if (c != '1')
		map->pos.posy += map->pos.dirx * speed;
	c = map->realmap[(int)(map->pos.posy)]
	[(int)(map->pos.posx - (map->pos.diry * 2 * speed))];
	if (c != '1')
		map->pos.posx -= map->pos.diry * speed;
}

void	ft_go_left(t_map *map, double speed)
{
	char	c;

	c = map->realmap[(int)(map->pos.posy
			- (map->pos.dirx * 2 * speed))][(int)map->pos.posx];
	if (c != '1')
		map->pos.posy -= map->pos.dirx * speed;
	c = map->realmap[(int)(map->pos.posy)]
	[(int)(map->pos.posx + (map->pos.diry * 2 * speed))];
	if (c != '1')
		map->pos.posx += map->pos.diry * speed;
}
