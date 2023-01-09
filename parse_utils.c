/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:40:21 by motroian          #+#    #+#             */
/*   Updated: 2023/01/06 19:33:06 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_putstr(char *s)
// {
// 	while (*s)
// 		write(1, &*s++, 1);
// }

char	**free_map(char **tab)
{
	int	j;

	j = -1;
	while (tab[++j])
		free(tab[j]);
	free (tab);
	return (NULL);
}

int	verif_n(char *str)
{
	int	i;
	int	len_i;

	if (!str)
		return (0);
	i = 0;
	len_i = ft_strlen(str);
	if (str[i] == '\n' || str[len_i - 1] == '\n')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_puttab(t_map *parse, int fd)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = get_next_line(fd);
	while (str)
	{
		tmp = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(fd);
	}
	parse->check = verif_n(tmp);
	if (parse->check == 1)
	{
		parse->map = ft_split(tmp, '\n');
		parse->map2 = ft_split(tmp, '\n');
	}
	free(tmp);
}

int	ft_strlentab(t_map *parse, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	parse->size_y = i;
	parse->size_x = ft_strlen(tab[0]);
	return (i);
}
