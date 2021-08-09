/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:02:28 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 16:18:55 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_texture_loop(double texpos, t_map *map, int x, int y)
{
	int		texy;
	int		texx;
	long	*color;

	texx = get_texx(map, map->wall);
	texy = get_texy(map, texpos);
	color = get_img_addr(map, texx, texy);
	ft_px_put(&map->img, x, y, *color);
}

int	ft_min(int elt1, int elt2)
{
	if (elt1 < elt2)
		return (elt1);
	return (elt2);
}

void	draw_texture(t_map *map, int x, int start, int end)
{
	int		y;
	double	step;
	double	texpos;

	y = start;
	step = get_step(map, start, end);
	if (map->pos.side == 0)
		map->wall = map->pos.posy + map->pos.dist * map->pos.raydiry;
	else
		map->wall = map->pos.posx + map->pos.dist * map->pos.raydirx;
	map->wall -= floor(map->wall);
	texpos = ((double)start - ((double)map->ry) / 2.0 + (
				(double)end - (double)start + 1.0) / 2.0) * step - 1;
	while (y < 0)
	{
		texpos += step;
		y++;
	}
	while (y < ft_min(end, map->ry - 1))
	{
		draw_texture_loop(texpos, map, x, y);
		texpos += step;
		y++;
	}
}

void	trace_col(t_map *map, int x)
{
	int	start;
	int	end;
	int	height;

	if (map->pos.side == 0)
		map->pos.dist = (map->pos.mapx - map->pos.posx
				+ ((1 - map->pos.stepx) / 2)) / map->pos.raydirx;
	else
		map->pos.dist = (map->pos.mapy - map->pos.posy
				+ ((1 - map->pos.stepy) / 2)) / map->pos.raydiry;
	map->pos.dist += 0.001;
	height = (int)map->ry / map->pos.dist;
	start = (map->ry - height) / 2;
	end = (map->ry + height) / 2;
	draw_line(map, x, 0, start);
	draw_line(map, x, end, map->ry - 1);
	draw_texture(map, x, start, end);
}
