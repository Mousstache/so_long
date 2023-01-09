/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:49:23 by motroian          #+#    #+#             */
/*   Updated: 2023/01/06 19:28:37 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->map.start[0];
	x = vars->map.start[1];
	if ((vars->map.map2[y - 1][x] == '1') || (vars->map.map2[y - 1][x] == 'E'
	&& vars->map.c < vars->map.count))
	{
		vars->map.map2[y][x] = 'P';
		vars->map.start[0] = y;
	}
	else
	{
		if (vars->map.map2[y - 1][x] == 'C')
			vars->map.c++;
		vars->map.map2[y - 1][x] = 'P';
		vars->map.map2[y][x] = '0';
		vars->map.start[0] = y - 1;
		vars->map.moves++;
		ft_printf(">%d\n", vars->map.moves);
	}
}

void	move_down(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->map.start[0];
	x = vars->map.start[1];
	if ((vars->map.map2[y + 1][x] == '1' ) || (vars->map.map2[y + 1][x] == 'E'
	&& vars->map.c < vars->map.count))
	{
		vars->map.map2[y][x] = 'P';
		vars->map.start[0] = y;
	}
	else
	{
		if (vars->map.map2[y + 1][x] == 'C')
			vars->map.c++;
		vars->map.map2[y + 1][x] = 'P';
		vars->map.map2[y][x] = '0';
		vars->map.start[0] = y + 1;
		vars->map.moves++;
		ft_printf(">%d\n", vars->map.moves);
	}
}

void	move_right(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->map.start[0];
	x = vars->map.start[1];
	if ((vars->map.map2[y][x + 1] == '1') || (vars->map.map2[y][x + 1] == 'E'
	&& vars->map.c < vars->map.count))
	{
		vars->map.map2[y][x] = 'P';
		vars->map.start[0] = y;
	}
	else
	{
		if (vars->map.map2[y][x + 1] == 'C')
			vars->map.c++;
		vars->map.map2[y][x + 1] = 'P';
		vars->map.map2[y][x] = '0';
		vars->map.start[1] = x + 1;
		vars->map.moves++;
		ft_printf(">%d\n", vars->map.moves);
	}
}

void	move_left(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->map.start[0];
	x = vars->map.start[1];
	if ((vars->map.map2[y][x - 1] == '1') || (vars->map.map2[y][x - 1] == 'E'
	&& vars->map.c < vars->map.count))
	{
		vars->map.map2[y][x] = 'P';
		vars->map.start[0] = y;
	}
	else
	{
		if (vars->map.map2[y][x - 1] == 'C')
			vars->map.c++;
		vars->map.map2[y][x - 1] = 'P';
		vars->map.map2[y][x] = '0';
		vars->map.start[1] = x - 1;
		vars->map.moves++;
		ft_printf(">%d\n", vars->map.moves);
	}
}
