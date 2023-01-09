/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:42:07 by motroian          #+#    #+#             */
/*   Updated: 2023/01/08 21:23:50 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include "mlx/mlx/mlx.h"

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define REALUP 65362
# define REALDOWN 65364
# define REALLEFT 65361
# define REALRIGHT 65363

# define WALL	'1'
# define GROUND '0'
# define COIN 'C'
# define PERSO 'P'
# define EXIT 'E'

typedef struct s_map
{
	int		bool;
	int		check;
	int		check_null;
	int		size_y;
	int		size_x;
	char	**map;
	char	**map2;
	int		count;
	int		start[2];
	int		exit[2];
	int		ife;
	int		ifp;
	int		c;
	int		moves;
}	t_map;

typedef struct s_data
{
	void	*img[7];
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_key
{
	int	up;
	int	down;
	int	right;
	int	left;
}			t_key;

typedef struct s_vars
{
	int		change;
	int		changeencore;
	void	*mlx;
	void	*win;
	t_key	key;
	t_map	map;
	t_data	data;
}	t_vars;

int		so_long(t_map *path, int fd, char *str);

//utils
char	**free_map(char **tab);
char	*get_next_line(int fd);
char	**ft_split(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_printf(const char *s, ...);
int		ft_putnbr(int nb);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_count(int nb);
int		h(unsigned long int nb, char *base);
size_t	ft_strlen(char *str);

//parsing
int		check_null(char *tmp);
int		check_ec(char **tab);
int		ft_parse(t_map *parse, int fd);
int		verif_n(char *str);
void	ft_puttab(t_map *parse, int fd);
int		ft_strlentab(t_map *parse, char **tab);
void	recup_data(t_map *map);
int		check_name(char *str);

//path_finding
int		path_finding(t_map *path);
void	make_x(t_map *path, int y, int x);

//partie graphique
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
void	display_map(t_map *map, void *mlx_win, void *mlx);
int		key_hook(int keycode, t_vars *vars);
int		mlx(t_map *map);
int		ft_close(t_vars *vars);
int		ft_close2(t_vars *vars);
void	free_img(t_vars *vars);
void	ft_putwall(t_vars *vars, int y, int x);

#endif