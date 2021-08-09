/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:23 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 11:01:33 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_fill_dir(t_map *map, char c)
{
	map->pos.dir = c;
	map->pos.dirx = 0;
	map->pos.diry = 0;
	map->pos.planx = 0;
	map->pos.plany = 0;
	if (c == 'N')
	{
		map->pos.diry = -1;
		map->pos.planx = 0.66;
	}
	if (c == 'E')
	{
		map->pos.dirx = 1;
		map->pos.plany = 0.66;
	}
	if (c == 'S')
	{
		map->pos.diry = 1;
		map->pos.planx = -0.66;
	}
	if (c == 'W')
	{
		map->pos.dirx = -1;
		map->pos.plany = -0.66;
	}
}

void	ft_px_put(t_vars *var, int x, int y, int color)
{
	char	*dst;

	dst = var->addr + (y * var->line_len + x * (var->bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_line(t_map *map, int x, int y1, int y2)
{
	double	pixels;
	double	pix_y;
	int		color;

	if (y1 < y2)
	{
		if (y1 == 0)
			color = map->ceiling.hexa;
		else
			color = map->floor.hexa;
		pix_y = y1;
		pixels = y2 - y1;
		while (pixels > 0)
		{
			ft_px_put(&map->img, x, pix_y, color);
			pix_y += 1;
			pixels--;
		}
	}
}

void	ft_posplayer(t_map *map, int size)
{
	int		line;
	int		col;
	int		color;
	char	c;

	line = 0;
	while (line < map->nblines)
	{
		col = 0;
		while (col < map->max)
		{
			c = map->realmap[line][col];
			col++;
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				map->pos.posy = line;
				map->pos.posx = col - 1;
				ft_fill_dir(map, c);
			}
		}
		line++;
	}
}
