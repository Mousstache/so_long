/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:39:14 by motroian          #+#    #+#             */
/*   Updated: 2023/01/08 21:24:56 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars *vars)
{
	int	y;
	int	x;

	y = -1;
	while (++y < vars->map.size_y)
	{
		x = -1;
		while (++x < vars->map.size_x)
		{
			if (vars->map.map2[y][x] == WALL)
				ft_putwall(vars, y, x);
			if (vars->map.map2[y][x] == GROUND)
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->data.img[0], x * 64, y * 64);
			if (vars->map.map2[y][x] == PERSO)
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->data.img[vars->change], x * 64, y * 64);
			if (vars->map.map2[y][x] == EXIT)
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->data.img[3], x * 64, y * 64);
			if (vars->map.map2[y][x] == COIN)
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->data.img[vars->changeencore], x * 64, y * 64);
		}
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307 || keycode == 113)
		ft_close(vars);
	if (keycode == UP || keycode == REALUP)
		move_up(vars);
	if (keycode == DOWN || keycode == REALDOWN)
		move_down(vars);
	if (keycode == RIGHT || keycode == REALRIGHT)
		move_right(vars);
	if (keycode == LEFT || keycode == REALLEFT)
		move_left(vars);
	if (keycode == 65437)
	{
		vars->change = 5;
		vars->changeencore = 6;
	}
	if (keycode == 65436)
	{
		vars->change = 2;
		vars->changeencore = 4;
	}
	draw_map(vars);
	if (check_ec(vars->map.map2) == 1)
		ft_close(vars);
	return (0);
}

void	init_image(t_vars *vars)
{
	int			a;
	int			i;
	int			j;
	static char	*name[7] = {
		"pics/sable.xpm", "pics/cactus.xpm", "pics/hajjj.xpm",
		"pics/masjid.xpm", "pics/eau.xpm", "pics/bonnemaman.xpm",
		"pics/petrol.xpm" };

	i = -1;
	j = -1;
	while (++i < 7)
	{
		vars->data.img[i] = mlx_xpm_file_to_image(vars->mlx,
				name[i], &a, &a);
		if (!vars->data.img[i])
		{
			while (++j < i)
				mlx_destroy_image(vars->mlx, vars->data.img[j]);
			ft_close2(vars);
		}
	}
}

int	mlx(t_map *map)
{
	void	*mlx;
	void	*win;
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (-1);
	vars->change = 2;
	vars->changeencore = 4;
	mlx = mlx_init();
	if (!mlx)
		exit(EXIT_FAILURE);
	win = mlx_new_window(mlx, map->size_x * 64, map->size_y * 64, "so_long");
	if (!win)
	{
		free(mlx);
		exit(EXIT_FAILURE);
	}
	vars->mlx = mlx;
	vars->win = win;
	vars->map = *map;
	mlx_key_hook(win, key_hook, vars);
	init_image(vars);
	draw_map(vars);
	mlx_hook(vars->win, 0, 1L << 0, &key_hook, vars);
	mlx_hook(vars->win, 17, 0, &ft_close, vars);
	mlx_loop(mlx);
	return (0);
}
