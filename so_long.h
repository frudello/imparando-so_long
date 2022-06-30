/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:10:15 by frudello          #+#    #+#             */
/*   Updated: 2022/06/30 18:47:26 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <mlx.h>
//# include "minilibx/mlx.h"
//# include "errors/sl_errors.h"

typedef struct	s_check {
	int		collect;
	int		exit;
	int		wall;
	int		space;
	int		enemy;
	int		x;
	int		y;
	bool	correct;
}				t_check;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int 	x;
	int 	y;
	void	*gerry;
}				t_mlx;

typedef struct	s_map {
	t_check	check;
	t_mlx	*mlx;
	int		collezionabile;
	int		mosse;
	int		pcolonne;
	int		prighe;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*r_gnl;
	char	**map;
}				t_map;



void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
char	*get_next_line(int fd);
void	initial_value(t_map *map);
char    **MAP(char *wam);
char	**ft_split(char const *s, char c);
void	walenght(t_map *map_s);
void	edges(t_map *map_s);
int		ft_strlen(const char *str);
void	areall(t_map *map_s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
void	muriamola(t_map *map_s);
void	move_up(t_map *map);
void	put_wall(t_map *m, int i, int j, char *s);
void	move_down(t_map *m);
void	move_right(t_map *m);
void	move_left(t_map *m);

#endif
