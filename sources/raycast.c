/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:33 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 10:01:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_raycast(t_map *map)
{
	int		x;
	char	c;
	int		i;

	x = 0;
	i = 0;
	mlx_clear_window(map->img.mlx, map->img.win);
	while (x < map->rx)
	{
		map->pos.cam = 2 * x / (double) map->rx - 1;
		map->pos.raydirx = map->pos.dirx + map->pos.planx * map->pos.cam;
		map->pos.raydiry = map->pos.diry + map->pos.plany * map->pos.cam;
		map->pos.mapx = (int)map->pos.posx;
		map->pos.mapy = (int)map->pos.posy;
		map->pos.deltadistx = sqrt(1 + (map->pos.raydiry * map->pos.raydiry)
				/ (map->pos.raydirx * map->pos.raydirx));
		map->pos.deltadisty = sqrt(1 + (map->pos.raydirx * map->pos.raydirx)
				/ (map->pos.raydiry * map->pos.raydiry));
		ft_stepside(map, x);
		x++;
	}
	mlx_put_image_to_window(map->img.mlx, map->img.win, map->img.img, 0, 0);
	return (1);
}

void	ft_stepside(t_map *map, int x)
{
	if (map->pos.raydirx >= 0)
	{
		map->pos.stepx = 1;
		map->pos.sidedistx = (1 + map->pos.mapx - map->pos.posx)
			* map->pos.deltadistx;
	}
	else
	{
		map->pos.stepx = -1;
		map->pos.sidedistx = (map->pos.posx - map->pos.mapx)
			* map->pos.deltadistx;
	}
	if (map->pos.raydiry >= 0)
	{
		map->pos.stepy = 1;
		map->pos.sidedisty = (1 + map->pos.mapy - map->pos.posy)
			* map->pos.deltadisty;
	}
	else
	{
		map->pos.stepy = -1;
		map->pos.sidedisty = (map->pos.posy - map->pos.mapy)
			* map->pos.deltadisty;
	}
	ft_checkhit(map, x);
}

void	ft_checkhit(t_map *map, int x)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (map->pos.sidedisty > map->pos.sidedistx)
		{
			map->pos.sidedistx += map->pos.deltadistx;
			map->pos.mapx += map->pos.stepx;
			map->pos.side = 0;
		}
		else
		{
			map->pos.sidedisty += map->pos.deltadisty;
			map->pos.mapy += map->pos.stepy;
			map->pos.side = 1;
		}
		if (map->realmap[map->pos.mapy][map->pos.mapx] == '1')
			hit = 1;
	}
	trace_col(map, x);
}
