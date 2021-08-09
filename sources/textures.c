/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:37 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 12:38:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_texture(t_map *map)
{
	map->no.img = mlx_xpm_file_to_image(map->img.mlx,
			map->no.path, &map->no.width, &map->no.height);
	if (map->no.width == 0)
		ft_error(ERR_PATH, PATH, map);
	map->no.addr = mlx_get_data_addr(map->no.img, &map->no.bpp,
			&map->no.len, &map->no.endian);
	map->so.img = mlx_xpm_file_to_image(map->img.mlx,
			map->so.path, &map->so.width, &map->so.height);
	if (map->so.width == 0)
		ft_error(ERR_PATH, PATH, map);
	map->so.addr = mlx_get_data_addr(map->so.img, &map->so.bpp,
			&map->so.len, &map->so.endian);
	map->ea.img = mlx_xpm_file_to_image(map->img.mlx,
			map->ea.path, &map->ea.width, &map->ea.height);
	if (map->ea.width == 0)
		ft_error(ERR_PATH, PATH, map);
	map->ea.addr = mlx_get_data_addr(map->ea.img, &map->ea.bpp,
			&map->ea.len, &map->ea.endian);
	map->we.img = mlx_xpm_file_to_image(map->img.mlx,
			map->we.path, &map->we.width, &map->we.height);
	if (map->we.width == 0)
		ft_error(ERR_PATH, PATH, map);
	map->we.addr = mlx_get_data_addr(map->we.img, &map->we.bpp,
			&map->we.len, &map->we.endian);
}

double	get_step(t_map *map, int start, int end)
{
	if (map->pos.side == 0 && map->pos.raydirx < 0)
		return ((double)(map->we.width) / (double)((double)end -
			(double)start + 1.0));
	else if (map->pos.side == 0 && map->pos.raydirx >= 0)
		return ((double)(map->ea.width) / (double)((double)end -
			(double)start + 1.0));
	else if (map->pos.side == 1 && map->pos.raydiry < 0)
		return ((double)(map->no.width) / (double)((double)end -
			(double)start + 1.0));
	else if (map->pos.side == 1 && map->pos.raydiry >= 0)
		return ((double)(map->so.width) / (double)((double)end -
			(double)start + 1.0));
	return (0);
}

int	get_texx(t_map *map, double wall)
{
	if (map->pos.side == 0 && map->pos.raydirx < 0)
		return ((int)((double)wall * map->we.width));
	else if (map->pos.side == 0 && map->pos.raydirx >= 0)
		return ((int)((1 - (double)wall) * map->ea.width - 1));
	else if (map->pos.side == 1 && map->pos.raydiry < 0)
		return ((int)((1 - (double)wall) * map->no.width - 1));
	else if (map->pos.side == 1 && map->pos.raydiry >= 0)
		return ((int)((double)wall * map->so.width));
	return (0);
}

int	get_texy(t_map *map, double texpos)
{
	if (map->pos.side == 0 && map->pos.raydirx < 0)
		return ((int)texpos & (map->we.height - 1));
	else if (map->pos.side == 0 && map->pos.raydirx >= 0)
		return ((int)texpos & (map->ea.height - 1));
	else if (map->pos.side == 1 && map->pos.raydiry < 0)
		return ((int)texpos & (map->no.height - 1));
	else if (map->pos.side == 1 && map->pos.raydiry >= 0)
		return ((int)texpos & (map->so.height - 1));
	return (0);
}

long	*get_img_addr(t_map *map, int texx, int texy)
{
	if (map->pos.side == 0 && map->pos.raydirx < 0)
		return ((long *)(map->we.addr + texy * map->we.len
			+ texx * map->we.bpp / 8));
	else if (map->pos.side == 0 && map->pos.raydirx >= 0)
		return ((long *)(map->ea.addr + texy * map->ea.len
			+ texx * map->ea.bpp / 8));
	else if (map->pos.side == 1 && map->pos.raydiry < 0)
		return ((long *)(map->no.addr + texy * map->no.len
			+ texx * map->no.bpp / 8));
	else if (map->pos.side == 1 && map->pos.raydiry >= 0)
		return ((long *)(map->so.addr + texy * map->so.len
			+ texx * map->so.bpp / 8));
	return (0);
}
