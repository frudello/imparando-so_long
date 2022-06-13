/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:10:15 by frudello          #+#    #+#             */
/*   Updated: 2022/06/13 15:08:58 by frudello         ###   ########.fr       */
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

typedef struct	s_map {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_map;

typedef struct s_bho {
	void	*mlx;
	void	*win;
	int 	x;
	int 	y;
	void	*gerry;
}				t_bho;

#endif