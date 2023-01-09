/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:52:58 by motroian          #+#    #+#             */
/*   Updated: 2023/01/08 19:17:39 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	recup_data(t_map *data)
{
	int	y;
	int	x;

	y = -1;
	x = 0;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				data->exit[0] = y;
				data->exit[1] = x;
				data->ife++;
			}
			if (data->map[y][x] == 'P')
			{
				data->start[0] = y;
				data->start[1] = x;
				data->ifp++;
			}
			x++;
		}
	}
}

int	check_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i -1] != 'r')
		return (0);
	if (str[i - 2] != 'e')
		return (0);
	if (str[i - 3] != 'b')
		return (0);
	if (str[i - 4] != '.')
		return (0);
	i = i - 5;
	while (str[i])
	{
		if (str[i] == '.')
			return (0);
		i--;
	}
	return (1);
}

void	ft_bzero(void *s, size_t n)
{
	char	*s2;
	int		i;

	s2 = (char *)s;
	i = 0;
	while (n > 0)
	{
		s2[i] = '\0';
		i++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = malloc(nmemb * size);
	if (!str)
		return (0);
	ft_bzero(str, nmemb * size);
	return (str);
}
