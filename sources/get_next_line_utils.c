/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:39:46 by clbouche          #+#    #+#             */
/*   Updated: 2021/07/12 17:08:13 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (s == d)
		return (dst);
	if (s > d)
	{
		while (len)
		{
			*d = *s;
			d++;
			s++;
			len--;
		}
	}
	else if (s < d)
	{
		while (len--)
		{
			*(d + len) = *(s + len);
		}
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(new))
		return (0);
	ft_memmove(new, s1, len1);
	ft_memmove(&new[len1], s2, len2);
	new[len1 + len2] = '\0';
	free((void *)s1);
	return (new);
}

char	*ft_form_line(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	s2 = malloc(sizeof(char) * i + 1);
	if (!(s2))
		return (0);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return ((char *)s2);
}
