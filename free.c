/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:53:31 by motroian          #+#    #+#             */
/*   Updated: 2023/01/07 17:56:00 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_vars *vars)
{
	free_img(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	mlx_loop_end(vars->mlx);
	free(vars->mlx);
	free_map(vars->map.map2);
	free_map(vars->map.map);
	free(vars);
	exit(1);
}

int	ft_close2(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	mlx_loop_end(vars->mlx);
	free(vars->mlx);
	free_map(vars->map.map2);
	free_map(vars->map.map);
	free(vars);
	exit(1);
}

void	free_img(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		mlx_destroy_image(vars->mlx, vars->data.img[i]);
		i++;
	}
}

void	ft_putwall(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->data.img[1], x * 64, y * 64);
}
