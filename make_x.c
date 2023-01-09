/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:09:29 by motroian          #+#    #+#             */
/*   Updated: 2023/01/03 20:36:21 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	col_down(t_map *path, int y, int x)
{
	while ((path->map[y][x] != '1') && (path->map[y][x] != 'E'))
	{
		if (path->map[y][x] != 'X')
		{
			path->bool = 1;
			path->map[y][x] = 'X';
		}
		y++;
		if (path->map[y][x] == 'E')
		{
			path->bool = 1;
			path->map[y][x] = '1';
		}
	}
}

void	col_up(t_map *path, int y, int x)
{
	while ((path->map[y][x] != '1') && (path->map[y][x] != 'E'))
	{
		if (path->map[y][x] != 'X')
		{
			path->bool = 1;
			path->map[y][x] = 'X';
		}
		y--;
		if (path->map[y][x] == 'E')
		{
			path->bool = 1;
			path->map[y][x] = '1';
		}
	}
}

void	line_right(t_map *path, int y, int x)
{
	while ((path->map[y][x] != '1') && (path->map[y][x] != 'E'))
	{
		if (path->map[y][x] != 'X')
		{
			path->bool = 1;
			path->map[y][x] = 'X';
		}
		x++;
		if (path->map[y][x] == 'E')
		{
			path->bool = 1;
			path->map[y][x] = '1';
		}
	}
}

void	line_left(t_map *path, int y, int x)
{
	while ((path->map[y][x] != '1') && (path->map[y][x] != 'E'))
	{
		if (path->map[y][x] != 'X')
		{
			path->bool = 1;
			path->map[y][x] = 'X';
		}
		x--;
		if (path->map[y][x] == 'E')
		{
			path->bool = 1;
			path->map[y][x] = '1';
		}
	}
}

void	make_x(t_map *path, int y, int x)
{
	col_up(path, y, x);
	col_down(path, y, x);
	line_right(path, y, x);
	line_left(path, y, x);
}
