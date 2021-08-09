/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:01:00 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 14:54:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_isdigit(int c, int i, int fin)
{
	if (i > fin)
		return (-1);
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (-1);
}

char	*ft_strcopy2(char *s, t_map *map)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * map->max + 1);
	if (!(dup))
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	while (i < map->max)
	{	
		dup[i] = ' ';
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_isspace(int c, int i, int fin)
{
	if (i > fin)
		return (-1);
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (-1);
}

int	valid(long n)
{
	if (n > 2147483647)
		return (2147483647);
	else
		return (n);
}

int	ft_atoi_new(const char *str, int i, int fin)
{
	long	n;

	while (i < fin)
	{
		while (str[i] == ' ')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error_bis(ERR_COLOR, COLOR);
		n = str[i] - '0';
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			n = 10 * n + (str[i] - '0');
			n = valid(n);
			i++;
		}
		while (i < fin)
		{
			if (str[i] != ' ' && str[i] != '\0')
				ft_error_bis(ERR_COLOR, COLOR);
			i++;
		}
		return (n);
	}
	ft_error_bis(ERR_COLOR, COLOR);
}
