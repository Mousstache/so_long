/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:35:13 by motroian          #+#    #+#             */
/*   Updated: 2023/01/08 21:22:30 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_map *map, int fd, char *str)
{
	if (check_name(str) == 0)
		return (ft_printf("\nError :\n\nNom De Map Invalide\n\n"), 0);
	if ((ft_parse(map, fd) == 0))
		return (ft_printf("\nError :\n\nMap Invalide\n\n"), 0);
	if (path_finding(map) == 0)
		return (ft_printf("\nError :\n\nPas De Chemin Accessible\n\n"), 0);
	if (mlx(map) == -1)
		return (ft_printf("\nError\n\n"));
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	static t_map	test = {0};
	int				fd;
	char			*str;

	if (!env || !*env)
		return (0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (ft_printf("Fichier invalide!\n"));
		str = argv[1];
		so_long(&test, fd, str);
		if (test.map)
			free_map(test.map2);
		if (test.map2)
			free_map(test.map);
		close(fd);
	}
	else
		return (0);
}
