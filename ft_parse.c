/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:41:02 by motroian          #+#    #+#             */
/*   Updated: 2023/01/06 20:28:54 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_101(char *str)
{
	int	j;
	int	i;

	i = 0;
	j = ft_strlen(str);
	if (str[0] != '1' || str[j - 1] != '1')
		return (0);
	while (str[i])
	{
		if ((str[i] != '1') && (str[i] != '0') && (str[i] != 'P')
			&& (str[i] != 'C') && str[i] != 'E')
			return (0);
		i++;
	}
	return (1);
}

int	check_len(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(tab[i]);
	while (tab[i])
	{
		if (ft_strlen(tab[i]) != (size_t)j)
			return (0);
		i++;
	}
	return (1);
}

int	check_ecp(t_map *parse, char **tab)
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
			if (tab[y][x] == 'C')
				parse->count++;
			x++;
		}
		y++;
	}
	recup_data(parse);
	if (parse->ife == 1 && parse->ifp == 1 && parse->count >= 1)
		return (1);
	return (0);
}

int	ft_parse(t_map *parse, int fd)
{
	int		y;
	int		i;

	ft_puttab(parse, fd);
	if (!parse->check)
		return (0);
	y = 1;
	i = ft_strlentab(parse, parse->map);
	if ((check_1(parse->map[0]) == 0) || (check_1(parse->map[i - 1]) == 0))
		return (0);
	if (check_len(parse->map) == 0)
		return (0);
	if (check_ecp(parse, parse->map) == 0)
		return (0);
	if (parse->check == 0)
		return (0);
	while (parse->map[y] && y < i)
	{
		if (check_101(parse->map[y]) == 0)
			return (0);
		y++;
	}
	return (1);
}
