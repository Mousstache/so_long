/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:51:02 by motroian          #+#    #+#             */
/*   Updated: 2023/01/03 20:37:21 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_find(t_map *path)
{
	char	**tab;
	int		x;
	int		y;

	y = 0;
	x = 0;
	tab = path->map;
	path->bool = -1;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P' || tab[y][x] == 'X')
			{
				make_x(path, y, x);
				tab[y][x] = 'X';
			}
			x++;
		}
		y++;
	}
}

int	check_ec(char **tab)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if ((tab[y][x] == 'E') || (tab[y][x] == 'C'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	path_finding(t_map *path)
{
	path->bool = 1;
	while (1)
	{
		path_find(path);
		if (path->bool == -1)
			break ;
	}
	if (check_ec(path->map) == 0)
		return (0);
	return (1);
}
