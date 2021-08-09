/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:09 by user42            #+#    #+#             */
/*   Updated: 2021/07/13 17:34:22 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	success(t_map *map)
{
	free_realmap(map);
	mlx_destroy_window(map->img.mlx, map->img.win);
	free(map->img.mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	deal_key(int key, t_map *map)
{
	double	speed;

	speed = 0.2;
	if (key == MOVE_TO_LEFT_A)
		ft_go_left(map, speed);
	if (key == FORWARD_W)
		ft_go_forward(map, speed);
	if (key == MOVE_TO_RIGHT_D)
		ft_go_right(map, speed);
	if (key == BACK_S)
		ft_go_back(map, speed);
	if (key == ROTATE_LEFT)
		ft_rotate_left(map);
	if (key == ROTATE_RIGHT)
		ft_rotate_right(map);
	if (key == ESC)
		success(map);
	return (0);
}

void	send_to_mlx(t_map *map)
{
	int		size;

	size = map->rx / (3 * map->max);
	map->img.mlx = mlx_init();
	ft_texture(map);
	mlx_get_screen_size(map->img.mlx, &map->screenx, &map->screeny);
	if (map->rx > map->screenx)
		map->rx = map->screenx;
	if (map->ry > map->screeny)
		map->ry = map->screeny;
	if (map->rx == 0 || map->ry == 0)
		ft_error(ERR_RESO, RESO, map);
	map->img.win = mlx_new_window(map->img.mlx, map->rx, map->ry, "CUB3D");
	map->img.img = mlx_new_image(map->img.mlx, map->rx, map->ry);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp,
			&map->img.line_len, &map->img.endian);
	ft_posplayer(map, size);
	mlx_hook(map->img.win, 2, 1L << 0, deal_key, map);
	mlx_hook(map->img.win, 33, 1L << 2, success, map);
	mlx_loop_hook(map->img.mlx, ft_raycast, map);
	mlx_loop(map->img.mlx);
}

int	main(int argc, char **argv)
{
	int		j;
	t_map	map;

	ft_bzero(&map);
	if (argc == 2)
	{
		check_cub(argv[1]);
		parse_cub(argv, &map);
	}
	else
		ft_error(ERR_ARG, NB_ARG, &map);
	send_to_mlx(&map);
	return (0);
}
