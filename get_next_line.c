/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:42:00 by motroian          #+#    #+#             */
/*   Updated: 2023/01/06 19:35:37 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_gnl(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_new(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*position;
	char			*tmp;
	char			*ret;
	int				reader;

	reader = 1;
	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (ft_check_gnl(position) == 1 && reader > 0)
	{
		reader = read(fd, str, BUFFER_SIZE);
		if (reader == -1)
			return (free(str), NULL);
		tmp = position;
		str[reader] = '\0';
		position = ft_strjoin(tmp, str);
	}
	ret = ft_substr(position, 0, ft_new(position) + 1);
	tmp = position;
	position = ft_substr(tmp, ft_new(tmp) + 1, (ft_strlen(tmp) - ft_new(tmp)));
	return (free(tmp), free(str), ret);
}
